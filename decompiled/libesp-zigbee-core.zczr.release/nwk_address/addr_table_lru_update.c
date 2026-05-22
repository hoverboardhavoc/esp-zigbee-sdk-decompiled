/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  undefined2 in_register_0000202e;
  int iVar2;
  nwk_addr_table_ent_t *pnVar3;
  uint uVar4;
  
  iVar2 = CONCAT22(in_register_0000202e,ref);
  if ((tbl->ents[iVar2].lru.prev != 0xffff) && (tbl->ents[iVar2].lru.next != 0xffff)) {
    addr_table_lru_remove(tbl,ref);
    pnVar3 = tbl->ents;
    if ((pnVar3[iVar2].lru.prev == 0xffff) || (pnVar3[iVar2].lru.next == 0xffff)) {
      if ((uint)tbl->lru_head < (uint)tbl->ent_nr) {
        uVar1 = pnVar3[tbl->lru_head].lru.prev;
        uVar4 = (uint)uVar1;
        pnVar3[iVar2].lru.prev = uVar1;
        pnVar3[iVar2].lru.next = pnVar3[uVar4].lru.next;
        if (uVar4 != 0xffff) {
          pnVar3[uVar4].lru.next = ref;
        }
        uVar4 = (uint)pnVar3[iVar2].lru.next;
        if (uVar4 != 0xffff) {
          pnVar3[uVar4].lru.prev = ref;
        }
      }
      else {
        pnVar3[iVar2].lru.prev = ref;
        pnVar3[iVar2].lru.next = ref;
      }
      tbl->lru_head = ref;
    }
    return;
  }
  return;
}

