/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_table_remove_by_dst
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_route_table_remove_by_dst(ezb_shortaddr_t dst_addr)

{
  undefined4 unaff_retaddr;
  uint uVar1;
  undefined4 unaff_s0;
  nwk_route_t *blk_busy;
  nwk_route_t *pnVar2;
  int iVar3;
  uint extraout_a1;
  bitmap_t *blk_busy_00;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_10 [4];
  
  pnVar2 = nwk_route_table_find(dst_addr);
  if (pnVar2 != (nwk_route_t *)0x0) {
    if (pnVar2->ref == '\0') {
      iVar3 = core_globals_get();
      blk_busy = *(nwk_route_t **)(iVar3 + 0xc58);
      iVar3 = core_globals_get();
      blk_busy_00 = *(bitmap_t **)(iVar3 + 0xc5c);
      iVar3 = core_globals_get();
      uVar5 = (uint)*(ushort *)(iVar3 + 0xc60);
      iVar3 = 0x10;
      if (pnVar2 < blk_busy) {
        register0x00002008 = (BADSPACEBASE *)auStack_10;
        unaff_retaddr = 0x10180;
        mempool_free_idx((bitmap_t *)blk_busy,(uint16_t)blk_busy_00,0x10);
      }
      uVar4 = ((int)pnVar2 - (int)blk_busy) / iVar3 & 0xffff;
      *(undefined4 *)((int)register0x00002008 + -4) = unaff_retaddr;
      *(undefined4 *)((int)register0x00002008 + -8) = unaff_s0;
      if (uVar4 < uVar5) goto _L0;
      do {
        mempool_free_idx(blk_busy_00,(uint16_t)uVar5,(uint16_t)uVar4);
_L0:
        uVar1 = 1 << (uVar4 & 7) & 0xff;
        uVar5 = uVar4 >> 3;
        uVar4 = 5;
        blk_busy_00 = (bitmap_t *)__atomic_fetch_and_1(blk_busy_00 + uVar5,~uVar1 & 0xff);
        uVar5 = extraout_a1;
      } while ((uVar1 & (uint)blk_busy_00) == 0);
      return;
    }
    *(ushort *)&pnVar2->field_0xe = *(ushort *)&pnVar2->field_0xe & 0xfff8 | 1;
  }
  return;
}

