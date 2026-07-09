/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_comm_set_tclk_exchange_required
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_comm_set_tclk_exchange_required(uint param_1)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xd5e) = *(byte *)(iVar1 + 0xd5e) & 0xfb | (byte)((param_1 & 1) << 2);
  iVar1 = aps_secur_is_tc();
  if (iVar1 != 0) {
    iVar1 = core_globals_get();
    *(ushort *)(iVar1 + 0x9bc) =
         *(ushort *)(iVar1 + 0x9bc) & 0xffe7 | (ushort)((param_1 + 1 & 3) << 3);
  }
  return;
}

