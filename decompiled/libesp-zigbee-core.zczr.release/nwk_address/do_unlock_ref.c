/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> do_unlock_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void do_unlock_ref(nwk_addr_table_t *tbl,nwk_addr_ref_t ref)

{
  ushort uVar1;
  _Bool _Var2;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined2 in_register_0000202e;
  nwk_addr_table_ent_t *pnVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar5 = CONCAT22(in_register_0000202e,ref);
  _Var2 = check_table_ref(ref,tbl->ent_in_use,tbl->ent_nr);
  if (CONCAT31(extraout_var_00,_Var2) != 0) {
    pnVar4 = tbl->ents + uVar5;
    uVar7 = (uint)pnVar4->ref_cnt;
    if (uVar7 == 0) {
      __assert_func(0,0,0,0);
    }
    pnVar4->ref_cnt = (uint8_t)(uVar7 - 1);
    if ((uVar7 - 1 & 0xff) == 0) {
      if ((*(ushort *)&pnVar4->ref_cnt >> 10 & 3) == 0) {
        pnVar4 = tbl->ents;
        if ((pnVar4[uVar5].lru.prev == 0xffff) || (pnVar4[uVar5].lru.next == 0xffff)) {
          if ((uint)tbl->lru_head < (uint)tbl->ent_nr) {
            uVar1 = pnVar4[tbl->lru_head].lru.prev;
            uVar7 = (uint)uVar1;
            pnVar4[uVar5].lru.prev = uVar1;
            pnVar4[uVar5].lru.next = pnVar4[uVar7].lru.next;
            if (uVar7 != 0xffff) {
              pnVar4[uVar7].lru.next = ref;
            }
            uVar5 = (uint)pnVar4[uVar5].lru.next;
            if (uVar5 != 0xffff) {
              pnVar4[uVar5].lru.prev = ref;
            }
          }
          else {
            pnVar4[uVar5].lru.prev = ref;
            pnVar4[uVar5].lru.next = ref;
          }
          tbl->lru_head = ref;
        }
        return;
      }
      iVar3 = core_globals_get();
      _Var2 = check_table_ref(ref,*(bitmap_t **)(iVar3 + 0xc4c),*(uint16_t *)(iVar3 + 0xc54));
      if (CONCAT31(extraout_var,_Var2) != 0) {
        iVar6 = *(int *)(iVar3 + 0xc50) + uVar5 * 0x12;
        if (*(char *)(iVar6 + 0x10) == '\0') {
          test_and_clr_bitmap(uVar5,*(bitmap_t **)(iVar3 + 0xc4c));
          addr_table_lru_remove((nwk_addr_table_t *)(iVar3 + 0xc4c),ref);
          memset((void *)(*(int *)(iVar3 + 0xc50) + uVar5 * 0x12),0,0x12);
          return;
        }
        *(byte *)(iVar6 + 0x11) = *(byte *)(iVar6 + 0x11) | 8;
      }
      return;
    }
  }
  return;
}

