/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_secur.o -> zdo_secur_finish_state
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_secur_finish_state(undefined4 param_1)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = core_globals_get();
  milli_timer_stop(iVar1 + 0xcfc);
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xcf8) = 0;
  iVar1 = core_globals_get();
  if (*(int *)(iVar1 + 0xd0c) != 0) {
    iVar1 = core_globals_get();
    UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0xd0c);
    iVar1 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x0001006c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1,*(undefined4 *)(iVar1 + 0xd10),UNRECOVERED_JUMPTABLE);
    return;
  }
  return;
}

