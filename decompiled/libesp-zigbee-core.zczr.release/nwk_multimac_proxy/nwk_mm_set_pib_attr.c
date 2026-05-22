/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_multimac_proxy.o -> nwk_mm_set_pib_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_mm_set_pib_attr(uint8_t iface_id,mac_pib_attr_t pib_attr,void *value)

{
  int iVar1;
  undefined3 in_register_00002029;
  int iVar2;
  ezb_err_t eVar3;
  undefined3 in_register_0000202d;
  code *UNRECOVERED_JUMPTABLE;
  
  if (CONCAT31(in_register_00002029,iface_id) != 0xff) {
    iVar2 = core_globals_get();
    iVar1 = CONCAT31(in_register_00002029,iface_id) * 0xc;
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(*(int *)(iVar2 + iVar1 + 0xc84) + 4) + 0xc);
    iVar2 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x000100a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    eVar3 = (*UNRECOVERED_JUMPTABLE)
                      (*(undefined4 *)(iVar2 + iVar1 + 0xc84),
                       CONCAT31(in_register_0000202d,pib_attr),value,UNRECOVERED_JUMPTABLE);
    return eVar3;
  }
  iVar2 = nwk_mm_iface_is_valid(0);
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar2 = core_globals_get();
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(*(int *)(iVar2 + 0xc84) + 4) + 0xc);
    iVar2 = core_globals_get();
    iVar2 = (*UNRECOVERED_JUMPTABLE)
                      (*(undefined4 *)(iVar2 + 0xc84),CONCAT31(in_register_0000202d,pib_attr),value)
    ;
    if (iVar2 != 0) {
      log_write(1,"nwk_multimac_proxy.c","%s on iface %d failed: %d",0x10000,0,iVar2);
      iVar1 = iVar2;
    }
  }
  return iVar1;
}

