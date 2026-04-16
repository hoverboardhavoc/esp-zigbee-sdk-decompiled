/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> mempool_alloc_ent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void * mempool_alloc_ent(void *blk_base,bitmap_t *blk_busy,uint16_t blk_size,uint16_t blk_nr)

{
  uint uVar1;
  uint16_t blk_idx;
  uint uVar2;
  uint uVar3;
  undefined2 in_register_00002032;
  undefined2 in_register_00002036;
  
  do {
    uVar2 = bitmap_find_first_zero_bit(blk_busy,CONCAT22(in_register_00002036,blk_nr));
    if (CONCAT22(in_register_00002036,blk_nr) <= uVar2) {
      return (void *)0x0;
    }
    uVar1 = 1 << (uVar2 & 7) & 0xff;
    uVar3 = __atomic_fetch_or_1(blk_busy + (uVar2 >> 3),uVar1,5);
  } while ((uVar1 & uVar3) != 0);
  return (void *)((int)blk_base + CONCAT22(in_register_00002032,blk_size) * uVar2);
}

