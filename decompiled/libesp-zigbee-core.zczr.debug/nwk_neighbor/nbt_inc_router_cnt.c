/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nbt_inc_router_cnt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void nbt_inc_router_cnt(int param_1)

{
  if ((int)(uint)*(ushort *)(param_1 + 0xe) <
      (int)((uint)*(ushort *)(param_1 + 8) - (uint)*(ushort *)(param_1 + 10))) {
    *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) + 1;
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xd3,
                "tbl->r_num < (tbl->ent_nr - tbl->ed_capacity)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

