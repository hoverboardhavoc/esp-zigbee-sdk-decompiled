/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_signal_device_left
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_comm_signal_device_left(undefined1 param_1)

{
  int iVar1;
  undefined1 auStack_14 [12];
  
  iVar1 = core_globals_get();
  auStack_14[0] = param_1;
  (**(code **)(iVar1 + 0xcd8))(1,auStack_14,*(code **)(iVar1 + 0xcd8));
  return;
}

