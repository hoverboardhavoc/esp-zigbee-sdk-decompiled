/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_multimac_proxy.o -> nwk_mm_get_pib_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_mm_get_pib_attr(uint8_t iface_id,mac_pib_attr_t pib_attr,void *value,size_t value_size
                             )

{
  undefined3 in_register_00002029;
  int iVar1;
  int iVar2;
  ezb_err_t eVar3;
  undefined3 in_register_0000202d;
  undefined4 uVar4;
  undefined4 extraout_a1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar4 = CONCAT31(in_register_0000202d,pib_attr);
  iVar1 = CONCAT31(in_register_00002029,iface_id);
  if (iVar1 == 0xff) {
    value_size = 0;
    value = (void *)0x0;
    iVar1 = __assert_func(0,0);
    uVar4 = extraout_a1;
  }
  iVar2 = core_globals_get();
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(*(int *)(iVar2 + iVar1 * 0xc + 0xce8) + 4) + 0xc);
  iVar2 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x00010112. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  eVar3 = (*UNRECOVERED_JUMPTABLE)
                    (*(undefined4 *)(iVar2 + iVar1 * 0xc + 0xce8),uVar4,value,value_size,
                     UNRECOVERED_JUMPTABLE);
  return eVar3;
}

