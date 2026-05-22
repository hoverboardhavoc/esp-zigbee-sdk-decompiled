/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_address_update(ezb_extaddr_t *extaddr,ezb_shortaddr_t shortaddr,nwk_addr_ref_t *ref_p)

{
  undefined4 *puVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  nwk_addr_table_t *tbl;
  nwk_addr_ref_t nVar8;
  nwk_addr_ref_t ref;
  int iVar9;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  ezb_err_t eVar12;
  undefined2 extraout_var_01;
  undefined2 in_register_0000202e;
  uint uVar13;
  int *piVar14;
  undefined1 *puVar15;
  uint uVar16;
  ezb_extaddr_t tmp_extaddr;
  uint uVar10;
  uint uVar11;
  
  iVar9 = core_globals_get();
  tbl = (nwk_addr_table_t *)(iVar9 + 0xc4c);
  if (CONCAT22(in_register_0000202e,shortaddr) < 0xfff8) {
    if (extaddr == (ezb_extaddr_t *)0x0) {
      eVar12 = 2;
    }
    else {
      iVar4 = *(int *)((int)&extaddr->field_0 + 4);
      if (*(int *)&extaddr->field_0 == 0 && iVar4 == 0) {
        eVar12 = 2;
      }
      else if ((*(int *)&extaddr->field_0 == -1) && (iVar4 == -1)) {
        eVar12 = 2;
      }
      else {
        nVar8 = search_short(tbl,shortaddr);
        uVar10 = CONCAT22(extraout_var,nVar8);
        uVar3 = *(ushort *)(iVar9 + 0xc54);
        ref = search_extended(tbl,extaddr);
        uVar11 = CONCAT22(extraout_var_00,ref);
        uVar13 = (uint)*(ushort *)(iVar9 + 0xc54);
        uVar16 = uVar10;
        if ((uVar10 < uVar3) && (uVar11 < uVar13)) {
          if (uVar10 != uVar11) {
            piVar14 = (int *)(uVar10 * 0x12 + *(int *)(iVar9 + 0xc50));
            if ((*piVar14 != 0 || piVar14[1] != 0) && ((*piVar14 != -1 || (piVar14[1] != -1)))) {
              *(byte *)((int)piVar14 + 0x11) = *(byte *)((int)piVar14 + 0x11) | 1;
              return 0xd;
            }
            if (*(byte *)(piVar14 + 4) == 0) {
              nwk_address_delete(nVar8);
              uVar16 = uVar11;
            }
            else {
              bVar2 = *(byte *)(*(int *)(iVar9 + 0xc50) + uVar11 * 0x12 + 0x10);
              if (bVar2 == 0) {
                nwk_address_delete(ref);
              }
              else if (bVar2 < *(byte *)(piVar14 + 4)) {
                addr_table_ref_redirect(tbl,ref,nVar8);
              }
              else {
                addr_table_ref_redirect(tbl,nVar8,ref);
                uVar16 = uVar11;
              }
            }
          }
        }
        else {
          uVar16 = uVar11;
          if (uVar13 <= uVar11) {
            uVar16 = uVar10;
          }
        }
        if (uVar10 < uVar3 || uVar11 < uVar13) {
          puVar15 = (undefined1 *)(*(int *)(iVar9 + 0xc50) + uVar16 * 0x12);
          uVar5 = *(undefined4 *)&extaddr->field_0;
          puVar1 = (undefined4 *)((int)&extaddr->field_0 + 4);
          uVar6 = *(undefined2 *)puVar1;
          uVar7 = *puVar1;
          *puVar15 = (char)*(undefined2 *)&extaddr->field_0;
          puVar15[1] = (char)((uint)uVar5 >> 8);
          puVar15[2] = (char)((uint)uVar5 >> 0x10);
          puVar15[3] = (char)((uint)uVar5 >> 0x18);
          puVar15[4] = (char)uVar6;
          puVar15[5] = (char)((uint)uVar7 >> 8);
          puVar15[6] = (char)((uint)uVar7 >> 0x10);
          puVar15[7] = (char)((uint)uVar7 >> 0x18);
          *(ezb_shortaddr_t *)(puVar15 + 8) = shortaddr;
          addr_table_lru_update(tbl,(nwk_addr_ref_t)uVar16);
        }
        else {
          nVar8 = addr_table_add(tbl,shortaddr,extaddr);
          uVar16 = CONCAT22(extraout_var_01,nVar8);
        }
        iVar9 = uVar16 * 0x12 + *(int *)(iVar9 + 0xc50);
        *(byte *)(iVar9 + 0x11) = *(byte *)(iVar9 + 0x11) & 0xfe;
        *ref_p = (nwk_addr_ref_t)uVar16;
        eVar12 = 0;
      }
    }
  }
  else {
    eVar12 = 2;
  }
  return eVar12;
}

