/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  ushort ref;
  uint n;
  nwk_addr_table_ent_t *pnVar1;
  uint uVar2;
  undefined1 auStack_28 [4];
  ezb_extaddr_t unknown_extaddr;
  
  auStack_28 = (undefined1  [4])0xffffffff;
  unknown_extaddr.field_0.u64._0_4_ = 0xffffffff;
  n = bitmap_find_first_zero_bit(tbl->ent_in_use,tbl->ent_nr);
  uVar2 = (uint)tbl->ent_nr;
  if (n < uVar2) {
    test_and_set_bitmap(n,tbl->ent_in_use);
    pnVar1 = tbl->ents;
    pnVar1[n].lru.next = 0xffff;
    pnVar1[n].lru.prev = 0xffff;
    addr_table_lru_add(tbl,(nwk_addr_ref_t)n);
    uVar2 = (uint)tbl->ent_nr;
    if (uVar2 <= n) goto _L0;
  }
  else {
_L0:
    if (uVar2 <= tbl->lru_head) {
      n = 0xffff;
      goto _L0;
    }
    pnVar1 = tbl->ents;
    ref = pnVar1[tbl->lru_head].lru.prev;
    n = (uint)ref;
    addr_table_lru_update(tbl,ref);
    if (uVar2 <= n) goto _L0;
  }
  pnVar1[n].shortaddr = shortaddr;
  if (extaddr == (ezb_extaddr_t *)0x0) {
    extaddr = (ezb_extaddr_t *)auStack_28;
  }
  nwk_extaddr_compress(extaddr,&pnVar1[n].extaddr_c);
_L0:
  return (nwk_addr_ref_t)n;
}

