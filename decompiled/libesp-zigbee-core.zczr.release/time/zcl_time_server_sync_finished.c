/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> time.o -> zcl_time_server_sync_finished
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_time_server_sync_finished(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  byte abStack_11 [9];
  
  milli_timer_stop(param_1 + 0xc);
  if (*(int *)(param_1 + 0x20) != -1) {
    iVar1 = time_server_get_attr_desc(*(undefined1 *)(param_1 + 0x25),1);
    abStack_11[0] = **(byte **)(iVar1 + 8) | 2;
    zcl_set_attr_value(*(undefined1 *)(param_1 + 0x25),10,1,0,abStack_11,0);
  }
  if (*(code **)(param_1 + 8) != (code *)0x0) {
    uVar2 = 7;
    if (*(int *)(param_1 + 0x20) != -1) {
      uVar2 = 0;
    }
                    /* WARNING: Could not recover jumptable at 0x0001010a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_1 + 8))(uVar2);
    return;
  }
  return;
}

