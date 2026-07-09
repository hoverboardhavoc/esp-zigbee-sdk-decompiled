/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_is_step_capable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool bdb_comm_is_step_capable(uint param_1)

{
  int iVar1;
  
  if (param_1 == 3) {
    iVar1 = core_globals_get();
    return (*(byte *)(iVar1 + 0xd4d) & 2) != 0;
  }
  if (param_1 < 4) {
    if (param_1 != 1) {
      if (param_1 == 2) {
        iVar1 = core_globals_get();
        return (bool)(*(byte *)(iVar1 + 0xd4d) & 1);
      }
      if (param_1 == 0) {
        return true;
      }
      return false;
    }
  }
  else {
    if (param_1 == 4) {
      iVar1 = core_globals_get();
      return (*(byte *)(iVar1 + 0xd4d) & 4) != 0;
    }
    if (param_1 != 5) {
      return false;
    }
  }
  iVar1 = core_globals_get();
  return (*(byte *)(iVar1 + 0xd4d) & 8) != 0;
}

