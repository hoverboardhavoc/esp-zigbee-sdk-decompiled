/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  nwk_addr_ref_t nVar2;
  _Bool _Var3;
  int iVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined2 in_register_0000202e;
  nwk_addr_table_ent_t *pnVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  uVar6 = CONCAT22(in_register_0000202e,ref);
  _Var3 = check_table_ref(ref,tbl->ent_in_use,tbl->ent_nr);
  if (CONCAT31(extraout_var_00,_Var3) != 0) {
    pnVar5 = tbl->ents + uVar6;
    uVar8 = (uint)pnVar5->ref_cnt;
    if (uVar8 == 0) {
      __assert_func(0,0,0,0);
    }
    pnVar5->ref_cnt = (uint8_t)(uVar8 - 1);
    if ((uVar8 - 1 & 0xff) == 0) {
      if ((*(ushort *)&pnVar5->ref_cnt >> 10 & 3) == 0) {
        pnVar5 = tbl->ents;
        if ((pnVar5[uVar6].lru.prev == 0xffff) || (pnVar5[uVar6].lru.next == 0xffff)) {
          if ((uint)tbl->lru_head < (uint)tbl->ent_nr) {
            uVar1 = pnVar5[tbl->lru_head].lru.prev;
            uVar8 = (uint)uVar1;
            nVar2 = pnVar5[uVar8].lru.next;
            pnVar5[uVar6].lru.prev = uVar1;
            pnVar5[uVar6].lru.next = nVar2;
            if (uVar8 != 0xffff) {
              pnVar5[uVar8].lru.next = ref;
            }
            uVar6 = (uint)pnVar5[uVar6].lru.next;
            if (uVar6 != 0xffff) {
              pnVar5[uVar6].lru.prev = ref;
            }
          }
          else {
            pnVar5[uVar6].lru.prev = ref;
            pnVar5[uVar6].lru.next = ref;
          }
          tbl->lru_head = ref;
        }
        return;
      }
      iVar4 = core_globals_get();
      _Var3 = check_table_ref(ref,*(bitmap_t **)(iVar4 + 0xcb0),*(uint16_t *)(iVar4 + 0xcb8));
      if (CONCAT31(extraout_var,_Var3) != 0) {
        iVar7 = *(int *)(iVar4 + 0xcb4) + uVar6 * 0x10;
        if (*(char *)(iVar7 + 0xe) == '\0') {
          test_and_clr_bitmap(uVar6,*(bitmap_t **)(iVar4 + 0xcb0));
          addr_table_lru_remove((nwk_addr_table_t *)(iVar4 + 0xcb0),ref);
          memset((void *)(*(int *)(iVar4 + 0xcb4) + uVar6 * 0x10),0,0x10);
          return;
        }
        *(byte *)(iVar7 + 0xf) = *(byte *)(iVar7 + 0xf) | 8;
      }
      return;
    }
  }
  return;
}

