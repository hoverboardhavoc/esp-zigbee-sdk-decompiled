/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_record_table_find_or_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_route_record_t * nwk_route_record_table_find_or_create(ezb_shortaddr_t dst_addr)

{
  undefined2 in_register_0000202a;
  uint uVar1;
  nwk_route_record_t *pnVar2;
  int iVar3;
  bitmap_t *blk_busy;
  void *blk_base;
  
  uVar1 = CONCAT22(in_register_0000202a,dst_addr);
  if (0xfff7 < uVar1) {
    uVar1 = __assert_func(0,0,0,0);
  }
  pnVar2 = nwk_route_record_table_find((ezb_shortaddr_t)uVar1);
  if (pnVar2 == (nwk_route_record_t *)0x0) {
    iVar3 = core_globals_get();
    blk_base = *(void **)(iVar3 + 0xc70);
    iVar3 = core_globals_get();
    blk_busy = *(bitmap_t **)(iVar3 + 0xc74);
    iVar3 = core_globals_get();
    pnVar2 = (nwk_route_record_t *)
             mempool_alloc_ent(blk_base,blk_busy,0x1c,*(uint16_t *)(iVar3 + 0xc78));
    if (pnVar2 != (nwk_route_record_t *)0x0) {
      memset(&pnVar2->relay_cnt,0,0x1a);
      pnVar2->dst_addr = (ezb_shortaddr_t)uVar1;
    }
  }
  return pnVar2;
}

