/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_network_steering_perform_join
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bdb_comm_network_steering_perform_join(void)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  if (((*(byte *)(iVar1 + 0xd5e) & 1) == 0) ||
     (iVar1 = core_globals_get(), *(int *)(iVar1 + 0xd54) == 0)) {
    iVar1 = core_globals_get();
    if (*(int *)(iVar1 + 0xd58) == 0) {
      iVar1 = core_globals_get();
      *(undefined1 *)(iVar1 + 0xd4c) = 3;
      bdb_comm_finish_network_steering();
      return;
    }
    iVar1 = core_globals_get();
    *(byte *)(iVar1 + 0xd5e) = *(byte *)(iVar1 + 0xd5e) & 0xfe;
  }
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xd4c) = 1;
  zdo_initiate_join();
  return;
}

