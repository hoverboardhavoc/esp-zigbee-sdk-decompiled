/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_set_pan_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_set_pan_channel(int param_1,undefined1 param_2,uint param_3)

{
  if (((*(uint *)(param_1 + 0x18) & 0x7ffffff) >> (param_3 & 0x1f) & 1) == 0) {
    return 2;
  }
  *(undefined1 *)(param_1 + 0x44) = param_2;
  *(char *)(param_1 + 0x43) = (char)param_3;
  if ((*(byte *)(param_1 + 0x9c) & 2) == 0) {
    *(undefined1 *)(param_1 + 0x42) = param_2;
    *(char *)(param_1 + 0x41) = (char)param_3;
    mac_do_idle();
    return 0;
  }
  return 0;
}

