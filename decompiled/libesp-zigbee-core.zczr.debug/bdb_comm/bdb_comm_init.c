/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bdb_comm_init(void)

{
  int iVar1;
  code *pcStack_18;
  code *pcStack_14;
  
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xda0) = 0;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xda1) = 0xb;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xda3) = 0;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xda2) = 6;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xda4) = 3;
  iVar1 = core_globals_get();
  *(undefined4 *)(iVar1 + 0xda8) = 0x2108800;
  iVar1 = core_globals_get();
  *(undefined4 *)(iVar1 + 0xdac) = 0x5ef7000;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xdb0) = 0;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0x9b9) = 0;
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0x9ba) = *(byte *)(iVar1 + 0x9ba) & 0xe0 | 5;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xdb1) = 0xf;
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xdb2) = *(byte *)(iVar1 + 0xdb2) | 1;
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xdb2) = *(byte *)(iVar1 + 0xdb2) | 4;
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xdb2) = *(byte *)(iVar1 + 0xdb2) & 0xf7;
  pcStack_18 = bdb_get_comm_param;
  pcStack_14 = bdb_handle_comm_signal;
  zdo_comm_force_linkage(&pcStack_18);
  touchlink_init();
  return;
}

