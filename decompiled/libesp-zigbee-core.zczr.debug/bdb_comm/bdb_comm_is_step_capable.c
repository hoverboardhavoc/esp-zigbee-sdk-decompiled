/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_is_step_capable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool bdb_comm_is_step_capable(bdb_comm_step_t step)

{
  undefined3 in_register_00002029;
  uint uVar1;
  int iVar2;
  
  uVar1 = CONCAT31(in_register_00002029,step);
  if (uVar1 == 3) {
    iVar2 = core_globals_get();
    return (*(byte *)(iVar2 + 0xd4d) & 2) != 0;
  }
  if (uVar1 < 4) {
    if (uVar1 != 1) {
      if (uVar1 == 2) {
        iVar2 = core_globals_get();
        return (_Bool)(*(byte *)(iVar2 + 0xd4d) & 1);
      }
      if (uVar1 == 0) {
        return true;
      }
      return false;
    }
  }
  else {
    if (uVar1 == 4) {
      iVar2 = core_globals_get();
      return (*(byte *)(iVar2 + 0xd4d) & 4) != 0;
    }
    if (uVar1 != 5) {
      return false;
    }
  }
  iVar2 = core_globals_get();
  return (*(byte *)(iVar2 + 0xd4d) & 8) != 0;
}

