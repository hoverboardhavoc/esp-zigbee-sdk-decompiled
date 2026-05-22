/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_comm_set_tclk_exchange_required
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bdb_comm_set_tclk_exchange_required(_Bool required)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xd5e) = *(byte *)(iVar1 + 0xd5e) & 0xfb | (byte)((required & 1) << 2);
  iVar1 = aps_secur_is_tc();
  if (iVar1 != 0) {
    iVar1 = core_globals_get();
    *(ushort *)(iVar1 + 0x9bc) =
         *(ushort *)(iVar1 + 0x9bc) & 0xffe7 | (ushort)((required + 1 & 3) << 3);
  }
  return;
}

