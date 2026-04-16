/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_update
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
  nwk_addr_table_t *tbl;
  nwk_addr_ref_t nVar4;
  nwk_addr_ref_t ref;
  int iVar5;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  ezb_err_t eVar8;
  undefined2 extraout_var_01;
  undefined2 in_register_0000202e;
  uint uVar9;
  uint uVar10;
  nwk_extaddr_c_t *extaddr_c;
  int iVar11;
  undefined1 auStack_38 [4];
  ezb_extaddr_t tmp_extaddr;
  uint uVar6;
  uint uVar7;
  
  iVar5 = core_globals_get();
  tbl = (nwk_addr_table_t *)(iVar5 + 0xcb0);
  if (CONCAT22(in_register_0000202e,shortaddr) < 0xfff8) {
    if (extaddr == (ezb_extaddr_t *)0x0) {
      eVar8 = 2;
    }
    else {
      iVar11 = *(int *)((int)&extaddr->field_0 + 4);
      if (*(int *)&extaddr->field_0 == 0 && iVar11 == 0) {
        eVar8 = 2;
      }
      else if ((*(int *)&extaddr->field_0 == -1) && (iVar11 == -1)) {
        eVar8 = 2;
      }
      else {
        nVar4 = search_short(tbl,shortaddr);
        uVar6 = CONCAT22(extraout_var,nVar4);
        uVar3 = *(ushort *)(iVar5 + 0xcb8);
        ref = search_extended(tbl,extaddr);
        uVar7 = CONCAT22(extraout_var_00,ref);
        uVar9 = (uint)*(ushort *)(iVar5 + 0xcb8);
        uVar10 = uVar6;
        if ((uVar6 < uVar3) && (uVar7 < uVar9)) {
          if (uVar6 != uVar7) {
            iVar11 = uVar6 * 0x10;
            nwk_extaddr_decompress
                      ((ezb_extaddr_t *)auStack_38,
                       (nwk_extaddr_c_t *)(*(int *)(iVar5 + 0xcb4) + iVar11));
            if ((auStack_38 != (undefined1  [4])0x0 || tmp_extaddr.field_0.u64._0_4_ != 0) &&
               ((auStack_38 != (undefined1  [4])0xffffffff || (tmp_extaddr.field_0.u64._0_4_ != -1))
               )) {
              iVar11 = *(int *)(iVar5 + 0xcb4) + iVar11;
              *(byte *)(iVar11 + 0xf) = *(byte *)(iVar11 + 0xf) | 1;
              return 0xd;
            }
            bVar1 = *(byte *)(iVar11 + *(int *)(iVar5 + 0xcb4) + 0xe);
            if (bVar1 == 0) {
              nwk_address_delete(nVar4);
              uVar10 = uVar7;
            }
            else {
              bVar2 = *(byte *)(*(int *)(iVar5 + 0xcb4) + uVar7 * 0x10 + 0xe);
              if (bVar2 == 0) {
                nwk_address_delete(ref);
              }
              else if (bVar2 < bVar1) {
                addr_table_ref_redirect(tbl,ref,nVar4);
              }
              else {
                addr_table_ref_redirect(tbl,nVar4,ref);
                uVar10 = uVar7;
              }
            }
          }
        }
        else {
          uVar10 = uVar7;
          if (uVar9 <= uVar7) {
            uVar10 = uVar6;
          }
        }
        if (uVar6 < uVar3 || uVar7 < uVar9) {
          extaddr_c = (nwk_extaddr_c_t *)(*(int *)(iVar5 + 0xcb4) + uVar10 * 0x10);
          nwk_extaddr_compress(extaddr,extaddr_c);
          *(ezb_shortaddr_t *)extaddr_c[1].device_id = shortaddr;
          addr_table_lru_update(tbl,(nwk_addr_ref_t)uVar10);
        }
        else {
          nVar4 = addr_table_add(tbl,shortaddr,extaddr);
          uVar10 = CONCAT22(extraout_var_01,nVar4);
        }
        iVar5 = *(int *)(iVar5 + 0xcb4) + uVar10 * 0x10;
        *(byte *)(iVar5 + 0xf) = *(byte *)(iVar5 + 0xf) & 0xfe;
        *ref_p = (nwk_addr_ref_t)uVar10;
        eVar8 = 0;
      }
    }
  }
  else {
    eVar8 = 2;
  }
  return eVar8;
}

