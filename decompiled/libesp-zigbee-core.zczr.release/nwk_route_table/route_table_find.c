/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> route_table_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_route_t * route_table_find(nwk_route_table_t *tbl,ezb_shortaddr_t dst_addr)

{
  undefined2 in_register_0000202e;
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    uVar1 = bitmap_find_next_bit(tbl->ent_in_use,tbl->ent_nr,uVar1);
    if (tbl->ent_nr <= uVar1) {
      return (nwk_route_t *)0x0;
    }
    if ((uint)tbl->ents[uVar1].dst_addr == CONCAT22(in_register_0000202e,dst_addr)) break;
    uVar1 = uVar1 + 1 & 0xffff;
  }
  return tbl->ents + uVar1;
}

