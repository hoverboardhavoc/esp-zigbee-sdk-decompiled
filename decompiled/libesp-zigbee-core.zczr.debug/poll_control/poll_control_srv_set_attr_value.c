/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_srv_set_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void poll_control_srv_set_attr_value(int param_1,undefined4 param_2)

{
  if (param_1 == 0xeff0) {
    ezb_zcl_set_attr_value(0x20,1,0xeff0,0x131b,param_2,0);
  }
  else {
    ezb_zcl_set_attr_value(0x20,1,0,0);
  }
  return;
}

