/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_set_ed_capacity
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_neighbor_table_set_ed_capacity(uint16_t capacity)

{
  uint16_t uVar1;
  undefined2 in_register_0000202a;
  int iVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  ezb_err_t eVar3;
  
  iVar2 = core_globals_get();
  uVar1 = nwk_neighbor_table_get_capacity();
  if (CONCAT22(extraout_var,uVar1) < CONCAT22(in_register_0000202a,capacity)) {
    eVar3 = 2;
  }
  else {
    uVar1 = nwk_neighbor_table_get_size();
    if (CONCAT22(extraout_var_00,uVar1) == 0) {
      *(uint16_t *)(iVar2 + 0xb26) = capacity;
      eVar3 = 0;
    }
    else {
      eVar3 = 0xd;
    }
  }
  return eVar3;
}

