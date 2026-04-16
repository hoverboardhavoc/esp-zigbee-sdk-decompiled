/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> addr_table_lru_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void addr_table_lru_update(nwk_addr_table_t *tbl,nwk_addr_ref_t ref)

{
  _Bool _Var1;
  undefined3 extraout_var;
  
  _Var1 = lru_queue_is_present(tbl,ref);
  if (CONCAT31(extraout_var,_Var1) != 0) {
    addr_table_lru_remove(tbl,ref);
    addr_table_lru_add(tbl,ref);
  }
  return;
}

