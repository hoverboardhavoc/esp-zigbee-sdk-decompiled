/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> addr_table_lru_reuse
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_addr_ref_t addr_table_lru_reuse(nwk_addr_table_t *tbl)

{
  nwk_addr_ref_t ref;
  
  if ((uint)tbl->lru_head < (uint)tbl->ent_nr) {
    ref = tbl->ents[tbl->lru_head].lru.prev;
    addr_table_lru_update(tbl,ref);
  }
  else {
    ref = 0xffff;
  }
  return ref;
}

