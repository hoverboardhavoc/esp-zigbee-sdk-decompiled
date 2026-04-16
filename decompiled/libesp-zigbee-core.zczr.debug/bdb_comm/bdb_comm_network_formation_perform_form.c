/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_network_formation_perform_form
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bdb_comm_network_formation_perform_form(void)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  if (((*(byte *)(iVar1 + 0xdb2) & 1) == 0) ||
     (iVar1 = core_globals_get(), *(int *)(iVar1 + 0xda8) == 0)) {
    iVar1 = core_globals_get();
    if (*(int *)(iVar1 + 0xdac) == 0) {
      iVar1 = core_globals_get();
      *(undefined1 *)(iVar1 + 0xda0) = 5;
      bdb_comm_finish_network_formation();
      return;
    }
    iVar1 = core_globals_get();
    *(byte *)(iVar1 + 0xdb2) = *(byte *)(iVar1 + 0xdb2) & 0xfe;
  }
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xda0) = 1;
  zdo_initiate_formation();
  return;
}

