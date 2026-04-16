/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  uVar4 = (uint)tbl->lru_head;
  if (uVar4 == uVar2) {
    uVar1 = tbl->ents[uVar2].lru.next;
    uVar4 = (uint)uVar1;
    tbl->lru_head = uVar1;
  }
  pnVar5 = tbl->ents;
  uVar1 = pnVar5[uVar2].lru.prev;
  if (uVar1 != 0xffff) {
    pnVar5[uVar1].lru.next = pnVar5[uVar2].lru.next;
  }
  uVar3 = (uint)pnVar5[uVar2].lru.next;
  if (uVar3 != 0xffff) {
    pnVar5[uVar3].lru.prev = uVar1;
  }
  pnVar5[uVar2].lru.prev = 0xffff;
  pnVar5[uVar2].lru.next = 0xffff;
  if (uVar2 == uVar4) {
    tbl->lru_head = 0xffff;
  }
  return;
}

