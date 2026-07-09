/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_start_top_level_commissioning
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 bdb_comm_start_top_level_commissioning(undefined1 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = core_globals_get();
  if ((*(char *)(iVar1 + 0xd4f) == '\0') &&
     (iVar1 = core_globals_get(), *(char *)(iVar1 + 0xd4e) == '\x06')) {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xd4f) = param_1;
    iVar1 = bdb_comm_is_on_network();
    if (iVar1 == 0) {
      uVar2 = zdo_dev_start_continue();
      return uVar2;
    }
    bdb_comm_start_commissioning();
    return 0;
  }
  return 9;
}

