/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void zdo_comm_init(void)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xd24) = 0;
  iVar1 = core_globals_get();
  *(undefined2 *)(iVar1 + 0xd26) = 0;
  iVar1 = core_globals_get();
  tasklet_init(iVar1 + 0xd28,zdo_comm_perform_next_op,0);
  return;
}

