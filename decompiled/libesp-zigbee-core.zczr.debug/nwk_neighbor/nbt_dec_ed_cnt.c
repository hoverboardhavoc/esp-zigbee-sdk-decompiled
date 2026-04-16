/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nbt_dec_ed_cnt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void nbt_dec_ed_cnt(nwk_neighbor_table_t *tbl)

{
  if (tbl->ed_num != 0) {
    tbl->ed_num = tbl->ed_num - 1;
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xe6,"nbt_dec_ed_cnt",0x10160);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

