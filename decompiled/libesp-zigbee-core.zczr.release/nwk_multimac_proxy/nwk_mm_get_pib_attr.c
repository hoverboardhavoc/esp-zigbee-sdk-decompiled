/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_multimac_proxy.o -> nwk_mm_get_pib_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_mm_get_pib_attr(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 extraout_a1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 == 0xff) {
    param_4 = 0;
    param_3 = 0;
    param_1 = __assert_func(0,0);
    param_2 = extraout_a1;
  }
  iVar1 = core_globals_get();
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(*(int *)(iVar1 + param_1 * 0xc + 0xc84) + 4) + 0x10);
  iVar1 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x00010182. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)
            (*(undefined4 *)(iVar1 + param_1 * 0xc + 0xc84),param_2,param_3,param_4,
             UNRECOVERED_JUMPTABLE);
  return;
}

