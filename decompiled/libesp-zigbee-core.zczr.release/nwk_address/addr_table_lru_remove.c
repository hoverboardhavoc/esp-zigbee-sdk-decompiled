/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> addr_table_lru_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void addr_table_lru_remove(nwk_addr_table_t *tbl,nwk_addr_ref_t ref)

{
  ushort uVar1;
  undefined2 in_register_0000202e;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  nwk_addr_table_ent_t *pnVar5;
  
  uVar2 = CONCAT22(in_register_0000202e,ref);
  uVar3 = (uint)tbl->lru_head;
  if (uVar3 == uVar2) {
    uVar1 = tbl->ents[uVar2].lru.next;
    uVar3 = (uint)uVar1;
    tbl->lru_head = uVar1;
  }
  pnVar5 = tbl->ents;
  uVar1 = pnVar5[uVar2].lru.prev;
  if (uVar1 != 0xffff) {
    pnVar5[uVar1].lru.next = pnVar5[uVar2].lru.next;
  }
  uVar4 = (uint)pnVar5[uVar2].lru.next;
  if (uVar4 != 0xffff) {
    pnVar5[uVar4].lru.prev = uVar1;
  }
  pnVar5[uVar2].lru.prev = 0xffff;
  pnVar5[uVar2].lru.next = 0xffff;
  if (uVar2 == uVar3) {
    tbl->lru_head = 0xffff;
  }
  return;
}

