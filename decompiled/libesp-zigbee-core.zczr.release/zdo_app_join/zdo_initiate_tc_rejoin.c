/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_join.o -> zdo_initiate_tc_rejoin
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void zdo_initiate_tc_rejoin(void)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xd40) = *(byte *)(iVar1 + 0xd40) | 1;
  iVar1 = core_globals_get();
  *(undefined2 *)(iVar1 + 0xd26) = 0x1d4;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xd24) = 0;
  iVar1 = core_globals_get();
  tasklet_post(iVar1 + 0xd28);
  return;
}

