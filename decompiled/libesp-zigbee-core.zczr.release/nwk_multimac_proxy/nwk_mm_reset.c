/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_multimac_proxy.o -> nwk_mm_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_mm_reset(uint8_t iface_id,_Bool set_default_pib)

{
  int iVar1;
  undefined3 in_register_00002029;
  int iVar2;
  undefined4 uVar3;
  ezb_err_t eVar4;
  undefined3 in_register_0000202d;
  code *UNRECOVERED_JUMPTABLE;
  
  if (CONCAT31(in_register_00002029,iface_id) == 0xff) {
    iVar1 = nwk_mm_is_iface_valid(0);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = core_globals_get();
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(*(int *)(iVar1 + 0xce8) + 4) + 4);
    iVar1 = core_globals_get();
    uVar3 = *(undefined4 *)(iVar1 + 0xce8);
  }
  else {
    iVar2 = core_globals_get();
    iVar1 = CONCAT31(in_register_00002029,iface_id) * 0xc;
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(*(int *)(iVar2 + iVar1 + 0xce8) + 4) + 4);
    iVar2 = core_globals_get();
    uVar3 = *(undefined4 *)(iVar2 + iVar1 + 0xce8);
  }
                    /* WARNING: Could not recover jumptable at 0x0001016a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  eVar4 = (*UNRECOVERED_JUMPTABLE)
                    (uVar3,CONCAT31(in_register_0000202d,set_default_pib),UNRECOVERED_JUMPTABLE);
  return eVar4;
}

