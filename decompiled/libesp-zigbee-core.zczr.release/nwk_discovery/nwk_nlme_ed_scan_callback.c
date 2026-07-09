/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_discovery.o -> nwk_nlme_ed_scan_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_nlme_ed_scan_callback(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  
  iVar1 = core_globals_get();
  if (*(code **)(iVar1 + 0xad0) != (code *)0x0) {
    if (param_1 == 0) {
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + 0xac0) = 0;
                    /* WARNING: Could not recover jumptable at 0x00010176. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar1 + 0xad0))(0,param_2,*(code **)(iVar1 + 0xad0));
      return;
    }
    uStack_14 = *(undefined1 *)(param_1 + 1);
    uStack_13 = *(undefined1 *)(param_1 + 2);
    uStack_12 = *(undefined1 *)(param_1 + 3);
    (**(code **)(iVar1 + 0xad0))(&uStack_14);
  }
  return;
}

