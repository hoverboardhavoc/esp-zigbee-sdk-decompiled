/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mempool.o -> mempool_malloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void * mempool_malloc(mempool_type_t type)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (MEMPOOL_TYPE_CUSTOM < type) {
    return (void *)0x0;
  }
  do {
    uVar2 = bitmap_find_first_zero_bit(s_mem_pools[type].blk_busy_map,s_mem_pools[type].blk_nr);
    if (s_mem_pools[type].blk_nr <= uVar2) {
      return (void *)0x0;
    }
    uVar1 = 1 << (uVar2 & 7) & 0xff;
    uVar3 = __atomic_fetch_or_1(s_mem_pools[type].blk_busy_map + (uVar2 >> 3),uVar1,5);
  } while ((uVar1 & uVar3) != 0);
  return s_mem_pools[type].base_mem + s_mem_pools[type].blk_size * uVar2;
}

