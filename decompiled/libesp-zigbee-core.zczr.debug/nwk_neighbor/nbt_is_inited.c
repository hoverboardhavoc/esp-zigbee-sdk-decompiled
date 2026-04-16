/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nbt_is_inited
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nbt_is_inited(nwk_neighbor_table_t *tbl)

{
  if (tbl->ent_nr == 0) {
    return false;
  }
  if (tbl->ents != (nwk_neighbor_t *)0x0) {
    if (tbl->ent_in_use != (bitmap_t *)0x0) {
      return true;
    }
    return false;
  }
  return false;
}

