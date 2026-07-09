/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_do_idle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_do_idle(int param_1)

{
  if (*(char *)(param_1 + 0x2e) != '\0') {
    return;
  }
  if (-1 < *(int *)(param_1 + 0x28) << 0xe) {
    mac_pal_sleep();
    return;
  }
  mac_pal_receive(*(undefined1 *)(param_1 + 0x42),*(undefined1 *)(param_1 + 0x41));
  return;
}

