/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_set_ic_required
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_comm_set_ic_required(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xd5e) = *(byte *)(iVar1 + 0xd5e) & 0xfd | (byte)((param_1 & 1) << 1);
  iVar1 = aps_secur_is_tc();
  if (iVar1 != 0) {
    if (param_1 == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = 2;
    }
    iVar2 = core_globals_get();
    *(ushort *)(iVar2 + 0x9bc) = *(ushort *)(iVar2 + 0x9bc) & 0xfff9 | (ushort)(iVar1 << 1);
  }
  return;
}

