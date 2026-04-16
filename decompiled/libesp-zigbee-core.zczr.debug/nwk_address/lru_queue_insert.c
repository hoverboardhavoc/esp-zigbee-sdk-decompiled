/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> lru_queue_insert
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void lru_queue_insert(nwk_addr_table_t *tbl,nwk_addr_ref_t prev_ref,nwk_addr_ref_t ref)

{
  undefined2 in_register_0000202e;
  uint uVar1;
  undefined2 in_register_00002032;
  int iVar2;
  
  iVar2 = CONCAT22(in_register_00002032,ref);
  tbl->ents[iVar2].lru.prev = prev_ref;
  tbl->ents[iVar2].lru.next = tbl->ents[CONCAT22(in_register_0000202e,prev_ref)].lru.next;
  uVar1 = (uint)tbl->ents[iVar2].lru.prev;
  if (uVar1 != 0xffff) {
    tbl->ents[uVar1].lru.next = ref;
  }
  uVar1 = (uint)tbl->ents[iVar2].lru.next;
  if (uVar1 != 0xffff) {
    tbl->ents[uVar1].lru.prev = ref;
  }
  return;
}

