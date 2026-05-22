/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_record_table_find_or_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_route_record_t * nwk_route_record_table_find_or_create(ezb_shortaddr_t dst_addr)

{
  ushort blk_nr;
  nwk_route_record_t *unaff_s0;
  uint16_t uVar1;
  undefined2 in_register_0000202a;
  int iVar2;
  undefined2 extraout_var;
  int iVar3;
  bitmap_t *blk_busy;
  
  if (CONCAT22(in_register_0000202a,dst_addr) < 0xfff8) {
    unaff_s0 = nwk_route_record_table_find(dst_addr);
    if (unaff_s0 != (nwk_route_record_t *)0x0) {
      return unaff_s0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_route_table.c",0x1bb,
                  "nwk_route_record_table_find_or_create","!((dst_addr) >= 0xfff8)");
  }
  iVar2 = core_globals_get();
  iVar3 = *(int *)(iVar2 + 0xc70);
  iVar2 = core_globals_get();
  blk_busy = *(bitmap_t **)(iVar2 + 0xc74);
  iVar2 = core_globals_get();
  blk_nr = *(ushort *)(iVar2 + 0xc78);
  uVar1 = mempool_alloc_idx(blk_busy,blk_nr);
  if ((CONCAT22(extraout_var,uVar1) < (uint)blk_nr) &&
     (unaff_s0 = (nwk_route_record_t *)(CONCAT22(extraout_var,uVar1) * 0x1c + iVar3),
     unaff_s0 != (nwk_route_record_t *)0x0)) {
    memset(unaff_s0,0,0x1c);
    unaff_s0->dst_addr = dst_addr;
  }
  return unaff_s0;
}

