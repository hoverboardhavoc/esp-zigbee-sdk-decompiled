/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_check_in_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void poll_control_check_in_timeout(byte *param_1)

{
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (param_1 != (byte *)0x0) {
    uStack_28 = 0;
    uStack_24 = 0;
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_14 = 0;
    iStack_20 = (uint)*param_1 << 0x18;
    ezb_zcl_poll_control_check_in_cmd_req(&uStack_28);
    nwk_pim_start_fast_poll(0);
    poll_control_check_in_start(*param_1);
  }
  return;
}

