/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_join.o -> zdo_comm_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_comm_init(void)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xcc0) = 0;
  iVar1 = core_globals_get();
  *(undefined2 *)(iVar1 + 0xcc2) = 0;
  iVar1 = core_globals_get();
  tasklet_init(iVar1 + 0xcc4,zdo_comm_perform_next_op,0);
  return;
}

