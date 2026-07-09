/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> mempool_free_idx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mempool_free_idx(undefined4 param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int extraout_a1;
  
  if ((param_3 < param_2) && (iVar1 = test_and_clr_bitmap(param_3,param_1), iVar1 != 0)) {
    return;
  }
  puVar2 = (undefined4 *)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.h",0x56,
                         "mempool_free_idx",
                         "(blk_idx < blk_nr) && test_and_clr_bitmap(blk_idx, blk_busy)");
  iVar1 = check_table_ref(extraout_a1,*puVar2,*(undefined2 *)(puVar2 + 2));
  if (iVar1 != 0) {
    iVar1 = puVar2[1] + extraout_a1 * 0x12;
    if (*(char *)(iVar1 + 0x10) == '\0') {
      test_and_clr_bitmap(extraout_a1,*puVar2);
      addr_table_lru_remove(puVar2,extraout_a1);
      memset((void *)(puVar2[1] + extraout_a1 * 0x12),0,0x12);
    }
    else {
      *(byte *)(iVar1 + 0x11) = *(byte *)(iVar1 + 0x11) | 8;
    }
  }
  return;
}

