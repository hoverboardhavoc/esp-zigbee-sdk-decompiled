/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_set_rx_on_when_idle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_set_rx_on_when_idle(int param_1,uint param_2)

{
  if ((*(uint *)(param_1 + 0x28) >> 0x11 & 1) != param_2) {
    *(byte *)(param_1 + 0x2a) = *(byte *)(param_1 + 0x2a) & 0xfd | (byte)((param_2 & 1) << 1);
    mac_pal_set_rx_when_idle(param_2);
    mac_do_idle(param_1);
  }
  return;
}

