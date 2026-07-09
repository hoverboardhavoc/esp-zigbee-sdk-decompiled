/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_clear_temporary_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_clear_temporary_channel(int param_1)

{
  if ((*(byte *)(param_1 + 0x9c) & 2) != 0) {
    *(byte *)(param_1 + 0x9c) = *(byte *)(param_1 + 0x9c) & 0xfd;
    *(undefined1 *)(param_1 + 0x42) = *(undefined1 *)(param_1 + 0x44);
    *(undefined1 *)(param_1 + 0x41) = *(undefined1 *)(param_1 + 0x43);
    mac_do_idle();
  }
  return;
}

