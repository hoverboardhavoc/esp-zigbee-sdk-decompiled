/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_dup.o -> aps_dup_table_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

aps_dup_t * aps_dup_table_find(aps_dup_table_t *tbl,aps_header_t *aps_hdr)

{
  byte bVar1;
  uint uVar2;
  aps_dup_t *paVar3;
  
  bVar1 = aps_hdr->fcf;
  uVar2 = 0;
  while( true ) {
    uVar2 = bitmap_find_next_bit(tbl->ent_in_use,tbl->ent_nr,uVar2);
    if (tbl->ent_nr <= uVar2) {
      return (aps_dup_t *)0x0;
    }
    paVar3 = tbl->ents + uVar2;
    if ((((paVar3->src_addr == (aps_hdr->addr_info).src_addr) &&
         (paVar3->aps_cntr == aps_hdr->aps_cntr)) &&
        ((*(ushort *)&paVar3->aps_cntr >> 0xe & 1) == (ushort)((bVar1 & 0xc) == 0))) &&
       (*(ushort *)&paVar3->aps_cntr >> 0xf == (ushort)((bVar1 & 3) == 1))) break;
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return paVar3;
}

