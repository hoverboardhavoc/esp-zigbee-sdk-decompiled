/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_frame_need_ack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte aps_frame_need_ack(int param_1)

{
  byte bVar1;
  
  if (0xfff7 < *(ushort *)(param_1 + 2)) {
    return 0;
  }
  bVar1 = *(byte *)(param_1 + 0xc);
  if (((bVar1 & 3) != 0) && ((bVar1 & 3) != 1)) {
    return 0;
  }
  return bVar1 >> 6 & 1;
}

