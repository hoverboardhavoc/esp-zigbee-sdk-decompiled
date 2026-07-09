/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_handle_device_left
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_handle_device_left(char *param_1)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  if ((*(char *)(iVar1 + 0xd4f) == '\0') && (*param_1 != '\0')) {
    bdb_comm_start_top_level_commissioning(1);
  }
  return;
}

