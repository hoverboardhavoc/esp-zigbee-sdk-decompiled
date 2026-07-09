/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_cmd_to_packet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zcl_touchlink_cmd_to_packet(int param_1,undefined4 param_2,undefined4 param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 2;
  }
  else {
    zcl_packet_setup_header(1,0,param_2,0,param_3);
    zcl_packet_setup_stamp(param_1,0,0,0x1000,0xc05e,*param_4,param_4 + 2);
    zcl_packet_add_payload(param_1,0,0);
    uVar1 = 0;
  }
  return uVar1;
}

