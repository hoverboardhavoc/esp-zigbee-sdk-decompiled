/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_record_table_remove_by_dst
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_route_record_table_remove_by_dst(ezb_shortaddr_t dst_addr)

{
  nwk_route_record_t *obj;
  int iVar1;
  void *blk_base;
  bitmap_t *blk_busy;
  
  obj = nwk_route_record_table_find(dst_addr);
  if (obj != (nwk_route_record_t *)0x0) {
    iVar1 = core_globals_get();
    blk_base = *(void **)(iVar1 + 0xc70);
    iVar1 = core_globals_get();
    blk_busy = *(bitmap_t **)(iVar1 + 0xc74);
    iVar1 = core_globals_get();
    mempool_free_ent(blk_base,blk_busy,0x1c,*(uint16_t *)(iVar1 + 0xc78),obj);
  }
  return;
}

