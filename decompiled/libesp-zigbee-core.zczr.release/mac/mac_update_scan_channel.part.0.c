/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_update_scan_channel.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_update_scan_channel_part_0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)*(byte *)(param_1 + 0x32);
  if ((uVar1 == 0xff) && (uVar1 = 0, *(uint *)(param_1 + 0x34) < 0x8000000)) {
    uVar1 = 10;
  }
  uVar1 = uVar1 + 1 & 0xff;
  do {
    uVar2 = uVar1;
    if (0x1a < (uVar2 & 0xff)) {
      return 5;
    }
    uVar1 = uVar2 + 1;
  } while (((*(uint *)(param_1 + 0x34) & 0x7ffffff) >> (uVar2 & 0x1f) & 1) == 0);
  *(char *)(param_1 + 0x32) = (char)uVar2;
  return 0;
}

