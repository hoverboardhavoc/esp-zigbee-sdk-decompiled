/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_finish_initialization
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bdb_comm_finish_initialization(void)

{
  ezb_app_signal_type_t signal;
  _Bool _Var1;
  undefined3 extraout_var;
  int iVar2;
  
  bdb_comm_finish_step();
  _Var1 = bdb_comm_is_factory_new();
  if (CONCAT31(extraout_var,_Var1) == 0) {
    signal = 0x101;
  }
  else {
    signal = 0x100;
  }
  iVar2 = core_globals_get();
  bdb_comm_put_app_signal(signal,*(bdb_comm_status_t *)(iVar2 + 0xda0));
  bdb_comm_perform_next_step();
  return;
}

