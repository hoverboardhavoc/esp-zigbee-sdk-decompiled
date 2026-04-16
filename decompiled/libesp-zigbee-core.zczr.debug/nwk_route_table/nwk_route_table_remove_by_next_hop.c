/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_table_remove_by_next_hop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_route_table_remove_by_next_hop(ezb_shortaddr_t next_hop)

{
  void *obj;
  undefined2 in_register_0000202a;
  int iVar1;
  int iVar2;
  uint uVar3;
  void *blk_base;
  bitmap_t *blk_busy;
  
  iVar1 = core_globals_get();
  uVar3 = 0;
  while (uVar3 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar1 + 0xcc0),*(undefined2 *)(iVar1 + 0xcc4),uVar3),
        uVar3 < *(ushort *)(iVar1 + 0xcc4)) {
    obj = (void *)(*(int *)(iVar1 + 0xcbc) + uVar3 * 0x10);
    if ((uint)*(ushort *)((int)obj + 2) == CONCAT22(in_register_0000202a,next_hop)) {
      if (*(char *)((int)obj + 0xc) == '\0') {
        iVar2 = core_globals_get();
        blk_base = *(void **)(iVar2 + 0xcbc);
        iVar2 = core_globals_get();
        blk_busy = *(bitmap_t **)(iVar2 + 0xcc0);
        iVar2 = core_globals_get();
        mempool_free_ent(blk_base,blk_busy,0x10,*(uint16_t *)(iVar2 + 0xcc4),obj);
      }
      else {
        *(ushort *)((int)obj + 0xe) = *(ushort *)((int)obj + 0xe) & 0xfff8 | 1;
      }
    }
    uVar3 = uVar3 + 1 & 0xffff;
  }
  return;
}

