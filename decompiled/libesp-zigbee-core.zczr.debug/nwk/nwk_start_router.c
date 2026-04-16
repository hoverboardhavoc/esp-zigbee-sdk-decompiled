/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_start_router
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
  int iVar3;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  int iStack_18;
  uint8_t *beacon_payload;
  uint8_t beacon_payload_length;
  
  _Var2 = nwk_is_joined();
  if ((CONCAT31(extraout_var,_Var2) == 0) ||
     (_Var2 = nwk_is_device_zczr(), CONCAT31(extraout_var_00,_Var2) == 0)) {
    return 0x2c2;
  }
  iVar3 = core_globals_get();
  *(uint *)(iVar3 + 0xce0) = *(uint *)(iVar3 + 0xce0) | 0x80;
  nwk_neighbor_table_restore();
  nwk_set_router_started(true);
  iVar3 = core_globals_get();
  cVar1 = *(char *)(iVar3 + 0xa3d);
  iVar3 = core_globals_get();
  beacon_payload._3_1_ = cVar1 + *(char *)(iVar3 + 0xa3e) + '\x0f';
  iStack_18 = core_globals_get();
  iStack_18 = iStack_18 + 0xa3f;
  iVar3 = nwk_mm_set_pib_attr(0xff,0x45,&iStack_18);
  if (iVar3 == 0) {
    iVar3 = nwk_mm_set_pib_attr(0xff,0x46,(int)&beacon_payload + 3);
    if (iVar3 == 0) {
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
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk.c",0x2d7,"nwk_start_router",
                  "(nwk_mm_set_pib_attr(0xFF, 0x45U, &beacon_payload)) == 0");
  }
  __assert_func("//build/esp-zigbee/src/core/nwk/nwk.c",0x2d8,"nwk_start_router",
                "(nwk_mm_set_pib_attr(0xFF, 0x46U, &beacon_payload_length)) == 0");
  _Var2 = nwk_is_joined_and_authed();
  if ((CONCAT31(extraout_var_01,_Var2) != 0) &&
     (_Var2 = nwk_is_device_zed(), CONCAT31(extraout_var_02,_Var2) != 0)) {
    iVar3 = core_globals_get();
    if (*(char *)(iVar3 + 0x9ee) == '\0') {
      nwk_pim_start_poll();
    }
    nwk_ed_start_keepalive();
    return 0;
  }
  return 0x2c2;
}

