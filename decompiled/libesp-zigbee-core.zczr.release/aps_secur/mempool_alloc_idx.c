/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> mempool_alloc_idx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t mempool_alloc_idx(bitmap_t *blk_busy,uint16_t blk_nr)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 in_register_0000202e;
  
  do {
    uVar2 = bitmap_find_first_zero_bit(blk_busy,CONCAT22(in_register_0000202e,blk_nr));
    if (CONCAT22(in_register_0000202e,blk_nr) <= uVar2) break;
    uVar1 = 1 << (uVar2 & 7) & 0xff;
    uVar3 = __atomic_fetch_or_1(blk_busy + (uVar2 >> 3),uVar1,5);
  } while ((uVar1 & uVar3) != 0);
  return (uint16_t)uVar2;
}

