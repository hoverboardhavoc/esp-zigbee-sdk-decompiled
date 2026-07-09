/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_frame_is_from_coord
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_frame_is_from_coord(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((*(char *)(param_2 + 0xe) == '\x02') &&
     (*(short *)(param_1 + 0xe) == *(short *)(param_2 + 0x10))) {
    uVar1 = 1;
  }
  else if (*(char *)(param_2 + 0xe) == '\x03') {
    if ((*(int *)(param_2 + 0x10) == *(int *)(param_1 + 0x10)) &&
       (*(int *)(param_2 + 0x14) == *(int *)(param_1 + 0x14))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

