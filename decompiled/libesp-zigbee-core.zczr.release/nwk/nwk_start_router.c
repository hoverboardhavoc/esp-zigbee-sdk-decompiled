/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_start_router
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_start_router(nwk_start_router_req_t *req)

{
  char cVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int iVar3;
  char cStack_15;
  int iStack_14;
  uint8_t beacon_payload_length;
  uint8_t *beacon_payload;
  
  _Var2 = nwk_is_joined();
  if ((CONCAT31(extraout_var,_Var2) != 0) &&
     (_Var2 = nwk_is_device_zczr(), CONCAT31(extraout_var_00,_Var2) != 0)) {
    nwk_neighbor_table_restore();
    _Var2 = nwk_is_device_zczr();
    if (CONCAT31(extraout_var_01,_Var2) != 0) goto _L0;
    do {
      __assert_func(0,0,0,0);
_L0:
      iVar3 = core_globals_get();
      *(byte *)(iVar3 + 0xb18) = *(byte *)(iVar3 + 0xb18) | 2;
      iVar3 = core_globals_get();
      cVar1 = *(char *)(iVar3 + 0xa3d);
      iVar3 = core_globals_get();
      cStack_15 = cVar1 + *(char *)(iVar3 + 0xa3e) + '\x0f';
      iStack_14 = core_globals_get();
      iStack_14 = iStack_14 + 0xa3f;
      iVar3 = nwk_mm_set_pib_attr(0xff,0x45,&stack0xffffffec);
    } while ((iVar3 != 0) || (iVar3 = nwk_mm_set_pib_attr(0xff,0x46,&cStack_15), iVar3 != 0));
    nwk_update_beacon_payload();
    iVar3 = core_globals_get();
    if (*(int *)(iVar3 + 0xac4) != 0) {
      iVar3 = core_globals_get();
      *(uint *)(*(int *)(iVar3 + 0xac4) + 0xc) =
           *(uint *)(*(int *)(iVar3 + 0xac4) + 0xc) & 0xfffffc3f | 0x80;
      iVar3 = core_globals_get();
      *(undefined4 *)(iVar3 + 0xac4) = 0;
    }
    nwk_link_mngr_set_enabled(1);
    time_ticker_register_receiver(1);
    return 0;
  }
  return 0x2c2;
}

