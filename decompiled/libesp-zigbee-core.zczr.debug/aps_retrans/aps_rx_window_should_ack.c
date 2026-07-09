/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_rx_window_should_ack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 aps_rx_window_should_ack(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_2 - (uint)*(byte *)(param_1 + 1);
  if ((uVar1 & 0xff) == *(byte *)(param_1 + 3) - 1) {
    return 1;
  }
  uVar1 = (1 << (((uint)*(byte *)(param_1 + 1) - param_2) + (uint)*(byte *)(param_1 + 3) & 0x1f)) +
          -1 << (uVar1 & 0x1f);
  if (uVar1 != (*(byte *)(param_1 + 4) & uVar1)) {
    return 0;
  }
  return 1;
}

