/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_setup_stamp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_packet_setup_stamp
               (int param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4,
               undefined2 param_5,undefined1 param_6,void *param_7)

{
  void *extraout_a1;
  
  if (param_7 == (void *)0x0) {
    param_4 = 0;
    param_3 = 0;
    param_1 = __assert_func(0,0);
    param_7 = extraout_a1;
  }
  *(undefined1 *)(param_1 + 0x15) = param_3;
  *(undefined1 *)(param_1 + 0x14) = param_2;
  *(undefined2 *)(param_1 + 0x16) = param_4;
  *(undefined2 *)(param_1 + 0x18) = param_5;
  *(undefined1 *)(param_1 + 10) = param_6;
  memcpy((void *)(param_1 + 0xc),param_7,8);
  return;
}

