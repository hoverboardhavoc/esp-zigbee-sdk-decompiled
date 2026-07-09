/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_set_length
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_set_length(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = zmsg_resize();
  if (iVar1 == 0) {
    *(short *)(param_1 + 0xe) = (short)param_2;
    if (param_2 < *(ushort *)(param_1 + 0x12)) {
      *(short *)(param_1 + 0x12) = (short)param_2;
    }
  }
  return;
}

