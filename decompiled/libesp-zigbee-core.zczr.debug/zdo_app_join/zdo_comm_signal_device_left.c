/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_signal_device_left
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_comm_signal_device_left(_Bool rejoin)

{
  int iVar1;
  undefined1 auStack_14 [12];
  
  iVar1 = core_globals_get();
  auStack_14[0] = rejoin;
  (**(code **)(iVar1 + 0xcd8))(1,auStack_14,*(code **)(iVar1 + 0xcd8));
  return;
}

