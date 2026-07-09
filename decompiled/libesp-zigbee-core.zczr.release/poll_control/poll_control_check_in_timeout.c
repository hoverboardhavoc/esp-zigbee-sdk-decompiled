/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> poll_control.o -> poll_control_check_in_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void poll_control_check_in_timeout(undefined1 *param_1)

{
  undefined1 auStack_28 [11];
  undefined1 uStack_1d;
  
  if (param_1 != (undefined1 *)0x0) {
    memset(auStack_28,0,0x18);
    uStack_1d = *param_1;
    ezb_zcl_poll_control_check_in_cmd_req(auStack_28);
    nwk_pim_start_fast_poll(0);
    poll_control_check_in_start(*param_1);
    return;
  }
  return;
}

