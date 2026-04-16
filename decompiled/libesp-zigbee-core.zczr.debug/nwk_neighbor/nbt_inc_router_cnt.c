/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nbt_inc_router_cnt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void nbt_inc_router_cnt(nwk_neighbor_table_t *tbl)

{
  if ((int)(uint)tbl->r_num < (int)((uint)tbl->ent_nr - (uint)tbl->ed_capacity)) {
    tbl->r_num = tbl->r_num + 1;
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xd4,"nbt_inc_router_cnt",
                "tbl->r_num < (tbl->ent_nr - tbl->ed_capacity)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

