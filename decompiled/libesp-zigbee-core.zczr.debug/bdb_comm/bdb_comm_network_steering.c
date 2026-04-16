/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_network_steering
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bdb_comm_network_steering(void)

{
  _Bool _Var1;
  int iVar2;
  undefined3 extraout_var;
  
  iVar2 = core_globals_get();
  *(undefined1 *)(iVar2 + 0xda0) = 1;
  _Var1 = bdb_comm_is_on_network();
  if (CONCAT31(extraout_var,_Var1) == 0) {
    bdb_comm_network_steering_off_network();
  }
  else {
    bdb_comm_network_steering_on_network();
  }
  return;
}

