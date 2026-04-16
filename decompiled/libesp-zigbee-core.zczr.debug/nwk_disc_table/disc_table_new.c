/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_disc_table.o -> disc_table_new
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_disc_table_ent_t * disc_table_new(nwk_disc_table_t *tbl)

{
  nwk_disc_table_ent_t *__s;
  uint n;
  
  n = bitmap_find_first_zero_bit(tbl->ent_in_use,6);
  if (n < 6) {
    test_and_set_bitmap(n,tbl->ent_in_use);
    __s = tbl->ents + n;
    memset(__s,0,0x14);
  }
  else {
    __s = (nwk_disc_table_ent_t *)0x0;
  }
  return __s;
}

