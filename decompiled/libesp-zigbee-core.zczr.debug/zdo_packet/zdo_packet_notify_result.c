/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_notify_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_packet_notify_result(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (*(int *)(param_1 + 4) != 0) {
    uStack_18 = param_2;
    uStack_14 = param_3;
    (**(code **)(param_1 + 4))(&uStack_18,*(undefined4 *)(param_1 + 8),*(code **)(param_1 + 4));
  }
  return;
}

