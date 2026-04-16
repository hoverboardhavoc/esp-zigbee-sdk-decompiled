/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> mempool_free_ent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mempool_free_ent(void *blk_base,bitmap_t *blk_busy,uint16_t blk_size,uint16_t blk_nr,void *obj)

{
  undefined4 unaff_retaddr;
  uint uVar1;
  undefined4 unaff_s0;
  uint extraout_a1;
  undefined2 in_register_00002032;
  int iVar2;
  uint uVar3;
  undefined2 in_register_00002036;
  uint uVar4;
  undefined1 auStack_10 [12];
  
  uVar4 = CONCAT22(in_register_00002036,blk_nr);
  iVar2 = CONCAT22(in_register_00002032,blk_size);
  if (obj < blk_base) {
    register0x00002008 = (BADSPACEBASE *)auStack_10;
    unaff_retaddr = 0x10180;
    mempool_free_idx((bitmap_t *)blk_base,(uint16_t)blk_busy,blk_size);
  }
  uVar3 = ((int)obj - (int)blk_base) / iVar2 & 0xffff;
  *(undefined4 *)((int)register0x00002008 + -4) = unaff_retaddr;
  *(undefined4 *)((int)register0x00002008 + -8) = unaff_s0;
  if (uVar3 < uVar4) goto _L0;
  do {
    mempool_free_idx(blk_busy,(uint16_t)uVar4,(uint16_t)uVar3);
_L0:
    uVar1 = 1 << (uVar3 & 7) & 0xff;
    uVar4 = uVar3 >> 3;
    uVar3 = 5;
    blk_busy = (bitmap_t *)__atomic_fetch_and_1(blk_busy + uVar4,~uVar1 & 0xff);
    uVar4 = extraout_a1;
  } while ((uVar1 & (uint)blk_busy) == 0);
  return;
}

