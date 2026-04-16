/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> addr_table_lru_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void addr_table_lru_update(nwk_addr_table_t *tbl,nwk_addr_ref_t ref)

{
  ushort uVar1;
  nwk_addr_ref_t nVar2;
  undefined2 in_register_0000202e;
  int iVar3;
  nwk_addr_table_ent_t *pnVar4;
  uint uVar5;
  
  iVar3 = CONCAT22(in_register_0000202e,ref);
  if ((tbl->ents[iVar3].lru.prev != 0xffff) && (tbl->ents[iVar3].lru.next != 0xffff)) {
    addr_table_lru_remove(tbl,ref);
    pnVar4 = tbl->ents;
    if ((pnVar4[iVar3].lru.prev == 0xffff) || (pnVar4[iVar3].lru.next == 0xffff)) {
      if ((uint)tbl->lru_head < (uint)tbl->ent_nr) {
        uVar1 = pnVar4[tbl->lru_head].lru.prev;
        uVar5 = (uint)uVar1;
        nVar2 = pnVar4[uVar5].lru.next;
        pnVar4[iVar3].lru.prev = uVar1;
        pnVar4[iVar3].lru.next = nVar2;
        if (uVar5 != 0xffff) {
          pnVar4[uVar5].lru.next = ref;
        }
        uVar5 = (uint)pnVar4[iVar3].lru.next;
        if (uVar5 != 0xffff) {
          pnVar4[uVar5].lru.prev = ref;
        }
      }
      else {
        pnVar4[iVar3].lru.prev = ref;
        pnVar4[iVar3].lru.next = ref;
      }
      tbl->lru_head = ref;
    }
    return;
  }
  return;
}

