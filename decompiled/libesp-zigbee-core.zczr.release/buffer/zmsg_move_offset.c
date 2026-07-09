/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_move_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_move_offset(int param_1,int param_2)

{
  int extraout_a1;
  
  param_2 = param_2 + (uint)*(ushort *)(param_1 + 0x12);
  if ((param_2 < 0) || ((int)(uint)*(ushort *)(param_1 + 0xe) < param_2)) {
    param_1 = __assert_func(0,0,0,0);
    param_2 = extraout_a1;
  }
  *(short *)(param_1 + 0x12) = (short)param_2;
  return;
}

