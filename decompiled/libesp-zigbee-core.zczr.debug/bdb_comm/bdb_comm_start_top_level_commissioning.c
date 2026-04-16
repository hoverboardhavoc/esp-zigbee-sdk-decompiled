/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_start_top_level_commissioning
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t bdb_comm_start_top_level_commissioning(uint8_t mode_mask)

{
  _Bool _Var1;
  int iVar2;
  undefined3 extraout_var;
  ezb_err_t eVar3;
  
  iVar2 = core_globals_get();
  if ((*(char *)(iVar2 + 0xda3) == '\0') &&
     (iVar2 = core_globals_get(), *(char *)(iVar2 + 0xda2) == '\x06')) {
    iVar2 = core_globals_get();
    *(uint8_t *)(iVar2 + 0xda3) = mode_mask;
    _Var1 = bdb_comm_is_on_network();
    if (CONCAT31(extraout_var,_Var1) == 0) {
      eVar3 = zdo_dev_start_continue();
      return eVar3;
    }
    bdb_comm_perform_next_step();
    return 0;
  }
  return 9;
}

