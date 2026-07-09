/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> mempool_free_idx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void mempool_free_idx(undefined4 param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  if ((param_3 < param_2) && (iVar1 = test_and_clr_bitmap(param_3,param_1), iVar1 != 0)) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.h",0x56,
                "mempool_free_idx","(blk_idx < blk_nr) && test_and_clr_bitmap(blk_idx, blk_busy)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

