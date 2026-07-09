/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_set_temporary_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_set_temporary_channel(int param_1,undefined1 param_2,uint param_3)

{
  if (((*(uint *)(param_1 + 0x18) & 0x7ffffff) >> (param_3 & 0x1f) & 1) != 0) {
    *(byte *)(param_1 + 0x9c) = *(byte *)(param_1 + 0x9c) | 2;
    *(undefined1 *)(param_1 + 0x42) = param_2;
    *(char *)(param_1 + 0x41) = (char)param_3;
    mac_do_idle();
  }
  return 0;
}

