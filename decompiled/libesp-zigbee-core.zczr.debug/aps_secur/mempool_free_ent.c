/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> mempool_free_ent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mempool_free_ent(void *blk_base,bitmap_t *blk_busy,uint16_t blk_size,uint16_t blk_nr,void *obj)

{
  uint uVar1;
  int extraout_a1;
  undefined2 in_register_00002032;
  
  if (blk_base <= obj) {
    mempool_free_idx(blk_busy,blk_nr,
                     (uint16_t)
                     (((int)obj - (int)blk_base) / CONCAT22(in_register_00002032,blk_size)));
    return;
  }
  uVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.h",0x69,
                        "mempool_free_ent","blk_base <= obj");
  __atomic_fetch_or_1((uVar1 >> 3) + extraout_a1,1 << (uVar1 & 7) & 0xff,5);
  return;
}

