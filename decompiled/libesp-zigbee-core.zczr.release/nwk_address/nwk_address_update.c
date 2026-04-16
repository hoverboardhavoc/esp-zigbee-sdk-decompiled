/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_address_update(ezb_extaddr_t *extaddr,ezb_shortaddr_t shortaddr,nwk_addr_ref_t *ref_p)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  nwk_addr_ref_t nVar5;
  nwk_addr_ref_t target_ref;
  int iVar6;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  nwk_addr_table_t *tbl;
  undefined2 extraout_var_01;
  undefined2 in_register_0000202e;
  int iVar8;
  nwk_extaddr_c_t *extaddr_c;
  nwk_addr_table_t *tbl_00;
  undefined1 auStack_38 [4];
  ezb_extaddr_t tmp_extaddr;
  uint uVar7;
  
  iVar6 = core_globals_get();
  if (0xfff7 < CONCAT22(in_register_0000202e,shortaddr)) {
    return 2;
  }
  if (extaddr == (ezb_extaddr_t *)0x0) {
    return 2;
  }
  if ((*(int *)((int)&extaddr->field_0 + 4) + 1U == (uint)(*(int *)&extaddr->field_0 == 0)) &&
     (0xfffffffd < *(int *)&extaddr->field_0 - 1U)) {
    return 2;
  }
  tbl_00 = (nwk_addr_table_t *)(iVar6 + 0xcb0);
  nVar5 = search_short(tbl_00,shortaddr);
  uVar4 = CONCAT22(extraout_var,nVar5);
  uVar3 = *(ushort *)(iVar6 + 0xcb8);
  target_ref = search_extended(tbl_00,extaddr);
  uVar7 = CONCAT22(extraout_var_00,target_ref);
  if (uVar4 < uVar3) {
    if ((uVar7 < *(ushort *)(iVar6 + 0xcb8)) && (uVar4 != uVar7)) {
      iVar8 = uVar4 * 0x10;
      nwk_extaddr_decompress
                ((ezb_extaddr_t *)auStack_38,(nwk_extaddr_c_t *)(*(int *)(iVar6 + 0xcb4) + iVar8));
      tbl = *(nwk_addr_table_t **)(iVar6 + 0xcb4);
      if ((tmp_extaddr.field_0.u64._0_4_ + 1 != (uint)(auStack_38 == (undefined1  [4])0x0)) ||
         ((int)auStack_38 - 1U < 0xfffffffe)) {
        *(byte *)((int)tbl + iVar8 + 0xf) = *(byte *)((int)tbl + iVar8 + 0xf) | 1;
        return 0xd;
      }
      bVar1 = *(byte *)((int)tbl + iVar8 + 0xe);
      if (bVar1 == 0) {
        nwk_address_delete(nVar5);
        uVar4 = uVar7;
      }
      else {
        bVar2 = *(byte *)((int)tbl + uVar7 * 0x10 + 0xe);
        if (bVar2 == 0) {
          nwk_address_delete(target_ref);
        }
        else if (bVar2 < bVar1) {
          addr_table_ref_redirect(tbl,target_ref,nVar5);
        }
        else {
          addr_table_ref_redirect(tbl,nVar5,target_ref);
          uVar4 = uVar7;
        }
      }
    }
  }
  else {
    uVar4 = uVar7;
    if (*(ushort *)(iVar6 + 0xcb8) <= uVar7) {
      nVar5 = addr_table_add(tbl_00,shortaddr,extaddr);
      uVar4 = CONCAT22(extraout_var_01,nVar5);
      goto _L0;
    }
  }
  extaddr_c = (nwk_extaddr_c_t *)(*(int *)(iVar6 + 0xcb4) + uVar4 * 0x10);
  nwk_extaddr_compress(extaddr,extaddr_c);
  *(ezb_shortaddr_t *)extaddr_c[1].device_id = shortaddr;
  addr_table_lru_update(tbl_00,(nwk_addr_ref_t)uVar4);
_L0:
  iVar6 = *(int *)(iVar6 + 0xcb4) + uVar4 * 0x10;
  *(byte *)(iVar6 + 0xf) = *(byte *)(iVar6 + 0xf) & 0xfe;
  *ref_p = (nwk_addr_ref_t)uVar4;
  return 0;
}

