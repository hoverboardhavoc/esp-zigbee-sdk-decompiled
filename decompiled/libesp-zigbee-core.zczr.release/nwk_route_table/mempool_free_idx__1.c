/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> mempool_free_idx__1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mempool_free_idx(bitmap_t *blk_busy,uint16_t blk_nr,uint16_t blk_idx)

{
  uint uVar1;
  undefined2 in_register_0000202e;
  uint extraout_a1;
  undefined2 in_register_00002032;
  uint uVar2;
  uint uVar3;
  
  uVar2 = CONCAT22(in_register_00002032,blk_idx);
  uVar3 = CONCAT22(in_register_0000202e,blk_nr);
  if (uVar2 < uVar3) goto _L0;
  do {
    mempool_free_idx(blk_busy,(uint16_t)uVar3,(uint16_t)uVar2);
_L0:
    uVar1 = 1 << (uVar2 & 7) & 0xff;
    uVar3 = uVar2 >> 3;
    uVar2 = 5;
    blk_busy = (bitmap_t *)__atomic_fetch_and_1(blk_busy + uVar3,~uVar1 & 0xff);
    uVar3 = extraout_a1;
  } while ((uVar1 & (uint)blk_busy) == 0);
  return;
}

