/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> mempool_free_ent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void mempool_free_ent(uint param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5)

{
  if (param_1 <= param_5) {
    mempool_free_idx(param_2,param_4,(int)(param_5 - param_1) / param_3 & 0xffff);
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.h",0x69,
                "mempool_free_ent","blk_base <= obj");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

