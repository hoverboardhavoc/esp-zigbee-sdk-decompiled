/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_is_valid_beacon_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_is_valid_beacon_frame(int param_1)

{
  ushort *puVar1;
  
  if ((*(ushort *)(param_1 + 0x1c) & 7) != 0) {
    return 0;
  }
  if (*(byte *)(param_1 + 0x20) < 4) {
    return 0;
  }
  puVar1 = *(ushort **)(param_1 + 0x24);
  if ((char)puVar1[1] != '\0') {
    return 0;
  }
  if (*(char *)((int)puVar1 + 3) == '\0') {
    if ((*puVar1 & 0xfff) != 0xfff) {
      return 0;
    }
    return 1;
  }
  return 0;
}

