/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_initialization
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bdb_comm_initialization(void)

{
  _Bool _Var1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  
  _Var1 = bdb_comm_is_on_network();
  if (CONCAT31(extraout_var,_Var1) == 0) {
    _Var1 = bdb_comm_is_factory_new();
    if (CONCAT31(extraout_var_00,_Var1) == 0) {
      bdb_comm_initialization_perform_network_recovery();
    }
    else {
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + 0xd4c) = 0;
      bdb_comm_finish_initialization();
    }
  }
  else {
    bdb_comm_finish_step();
    bdb_comm_perform_next_step();
  }
  return;
}

