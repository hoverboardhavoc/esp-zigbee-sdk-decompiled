/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> addr_table_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_addr_ref_t
addr_table_add(nwk_addr_table_t *tbl,ezb_shortaddr_t shortaddr,ezb_extaddr_t *extaddr)

{
  undefined4 *puVar1;
  ushort ref;
  undefined4 uVar2;
  undefined3 uVar3;
  undefined4 uVar4;
  uint n;
  uint uVar5;
  nwk_addr_table_ent_t *pnVar6;
  undefined1 local_28 [4];
  ezb_extaddr_t unknown_extaddr;
  
  local_28 = (undefined1  [4])0xffffffff;
  unknown_extaddr.field_0.u64._0_4_ = 0xffffffff;
  n = bitmap_find_first_zero_bit(tbl->ent_in_use,tbl->ent_nr);
  uVar5 = (uint)tbl->ent_nr;
  if (n < uVar5) {
    test_and_set_bitmap(n,tbl->ent_in_use);
    pnVar6 = tbl->ents;
    pnVar6[n].lru.next = 0xffff;
    pnVar6[n].lru.prev = 0xffff;
    addr_table_lru_add(tbl,(nwk_addr_ref_t)n);
    uVar5 = (uint)tbl->ent_nr;
    if (uVar5 <= n) goto _L0;
  }
  else {
_L0:
    if (uVar5 <= tbl->lru_head) {
      n = 0xffff;
      goto _L0;
    }
    pnVar6 = tbl->ents;
    ref = pnVar6[tbl->lru_head].lru.prev;
    n = (uint)ref;
    addr_table_lru_update(tbl,ref);
    if (uVar5 <= n) goto _L0;
  }
  pnVar6 = pnVar6 + n;
  pnVar6->shortaddr = shortaddr;
  if (extaddr == (ezb_extaddr_t *)0x0) {
    extaddr = (ezb_extaddr_t *)local_28;
  }
  puVar1 = (undefined4 *)((int)&extaddr->field_0 + 4);
  uVar2 = *(undefined4 *)&extaddr->field_0;
  uVar3 = *(undefined3 *)puVar1;
  uVar4 = *puVar1;
  (pnVar6->extaddr).field_0.u8[0] = (uint8_t)*(undefined3 *)&extaddr->field_0;
  (pnVar6->extaddr).field_0.u8[1] = (uint8_t)((uint)uVar2 >> 8);
  (pnVar6->extaddr).field_0.u8[3] = (uint8_t)((uint)uVar2 >> 0x18);
  (pnVar6->extaddr).field_0.u8[5] = (uint8_t)((uint)uVar4 >> 8);
  (pnVar6->extaddr).field_0.u8[2] = (uint8_t)((uint)uVar2 >> 0x10);
  (pnVar6->extaddr).field_0.u8[4] = (uint8_t)uVar3;
  (pnVar6->extaddr).field_0.u8[6] = (uint8_t)((uint)uVar4 >> 0x10);
  (pnVar6->extaddr).field_0.u8[7] = (uint8_t)((uint)uVar4 >> 0x18);
_L0:
  return (nwk_addr_ref_t)n;
}

