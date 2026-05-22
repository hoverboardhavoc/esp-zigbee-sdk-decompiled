/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_comm_init
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
  *(undefined1 *)(iVar1 + 0xd4c) = 0;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xd4d) = 0xb;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xd4f) = 0;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xd4e) = 6;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xd50) = 3;
  iVar1 = core_globals_get();
  *(undefined4 *)(iVar1 + 0xd54) = 0x2108800;
  iVar1 = core_globals_get();
  *(undefined4 *)(iVar1 + 0xd58) = 0x5ef7000;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xd5c) = 0;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0x9b9) = 0;
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0x9ba) = *(byte *)(iVar1 + 0x9ba) & 0xe0 | 5;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xd5d) = 0xf;
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xd5e) = *(byte *)(iVar1 + 0xd5e) | 1;
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xd5e) = *(byte *)(iVar1 + 0xd5e) | 4;
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xd5e) = *(byte *)(iVar1 + 0xd5e) & 0xf7;
  pcStack_18 = bdb_get_comm_param;
  pcStack_14 = bdb_handle_comm_signal;
  zdo_comm_force_linkage(&pcStack_18);
  touchlink_init();
  iVar1 = core_globals_get();
  tasklet_init(iVar1 + 0xd3c,bdb_comm_task,0);
  return;
}

