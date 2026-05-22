/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> search_extended
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_addr_ref_t search_extended(nwk_addr_table_t *tbl,ezb_extaddr_t *extaddr)

{
  uint uVar1;
  nwk_addr_table_ent_t *pnVar2;
  
  uVar1 = 0;
  while (uVar1 = bitmap_find_next_bit(tbl->ent_in_use,tbl->ent_nr,uVar1), uVar1 < tbl->ent_nr) {
    pnVar2 = tbl->ents + uVar1;
    if ((*(ushort *)&pnVar2->ref_cnt >> 10 & 1) == 0) {
      if ((*(int *)&extaddr->field_0 == *(int *)&(pnVar2->extaddr).field_0) &&
         (*(int *)((int)&extaddr->field_0 + 4) == *(int *)((int)&(pnVar2->extaddr).field_0 + 4)))
      break;
    }
    uVar1 = uVar1 + 1 & 0xffff;
  }
  return (nwk_addr_ref_t)uVar1;
}

