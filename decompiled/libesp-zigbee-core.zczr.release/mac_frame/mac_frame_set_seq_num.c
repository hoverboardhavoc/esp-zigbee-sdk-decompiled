/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_frame.o -> mac_frame_set_seq_num
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_frame_set_seq_num(undefined4 *param_1,undefined1 param_2)

{
  undefined1 extraout_a1;
  ushort *puVar1;
  
  puVar1 = (ushort *)*param_1;
  if ((*puVar1 & 0x100) != 0) {
    __assert_func(0,0,0,0);
    param_2 = extraout_a1;
  }
  *(undefined1 *)(puVar1 + 1) = param_2;
  return;
}

