/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
                           (*(undefined4 *)(iVar1 + 0xc5c),*(undefined2 *)(iVar1 + 0xc60),uVar3),
        uVar3 < *(ushort *)(iVar1 + 0xc60)) {
    obj = (void *)(*(int *)(iVar1 + 0xc58) + uVar3 * 0x10);
    if ((uint)*(ushort *)((int)obj + 2) == CONCAT22(in_register_0000202a,next_hop)) {
      if (*(char *)((int)obj + 0xc) == '\0') {
        iVar2 = core_globals_get();
        blk_base = *(void **)(iVar2 + 0xc58);
        iVar2 = core_globals_get();
        blk_busy = *(bitmap_t **)(iVar2 + 0xc5c);
        iVar2 = core_globals_get();
        mempool_free_ent(blk_base,blk_busy,0x10,*(uint16_t *)(iVar2 + 0xc60),obj);
      }
      else {
        *(ushort *)((int)obj + 0xe) = *(ushort *)((int)obj + 0xe) & 0xfff8 | 1;
      }
    }
    uVar3 = uVar3 + 1 & 0xffff;
  }
  return;
}

