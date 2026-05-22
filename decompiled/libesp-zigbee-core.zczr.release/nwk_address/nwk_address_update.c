/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_update
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
  undefined2 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  nwk_addr_ref_t nVar8;
  nwk_addr_ref_t target_ref;
  int iVar9;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 in_register_0000202e;
  int *piVar11;
  undefined1 *puVar12;
  nwk_addr_table_t *tbl;
  nwk_addr_table_t *tbl_00;
  uint uVar10;
  
  iVar9 = core_globals_get();
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
  tbl_00 = (nwk_addr_table_t *)(iVar9 + 0xc4c);
  nVar8 = search_short(tbl_00,shortaddr);
  uVar7 = CONCAT22(extraout_var,nVar8);
  uVar3 = *(ushort *)(iVar9 + 0xc54);
  target_ref = search_extended(tbl_00,extaddr);
  uVar10 = CONCAT22(extraout_var_00,target_ref);
  if (uVar7 < uVar3) {
    if ((uVar10 < *(ushort *)(iVar9 + 0xc54)) && (uVar7 != uVar10)) {
      tbl = *(nwk_addr_table_t **)(iVar9 + 0xc50);
      piVar11 = (int *)(uVar7 * 0x12 + (int)tbl);
      if ((piVar11[1] + 1U != (uint)(*piVar11 == 0)) || (*piVar11 - 1U < 0xfffffffe)) {
        *(byte *)((int)piVar11 + 0x11) = *(byte *)((int)piVar11 + 0x11) | 1;
        return 0xd;
      }
      if (*(byte *)(piVar11 + 4) == 0) {
        nwk_address_delete(nVar8);
        uVar7 = uVar10;
      }
      else {
        bVar2 = *(byte *)((int)tbl + uVar10 * 0x12 + 0x10);
        if (bVar2 == 0) {
          nwk_address_delete(target_ref);
        }
        else if (bVar2 < *(byte *)(piVar11 + 4)) {
          addr_table_ref_redirect(tbl,target_ref,nVar8);
        }
        else {
          addr_table_ref_redirect(tbl,nVar8,target_ref);
          uVar7 = uVar10;
        }
      }
    }
  }
  else {
    uVar7 = uVar10;
    if (*(ushort *)(iVar9 + 0xc54) <= uVar10) {
      nVar8 = addr_table_add(tbl_00,shortaddr,extaddr);
      uVar7 = CONCAT22(extraout_var_01,nVar8);
      goto _L0;
    }
  }
  puVar1 = (undefined4 *)((int)&extaddr->field_0 + 4);
  puVar12 = (undefined1 *)(*(int *)(iVar9 + 0xc50) + uVar7 * 0x12);
  uVar4 = *(undefined2 *)puVar1;
  uVar5 = *(undefined4 *)&extaddr->field_0;
  uVar6 = *puVar1;
  *puVar12 = (char)*(undefined2 *)&extaddr->field_0;
  puVar12[1] = (char)((uint)uVar5 >> 8);
  puVar12[3] = (char)((uint)uVar5 >> 0x18);
  puVar12[5] = (char)((uint)uVar6 >> 8);
  puVar12[2] = (char)((uint)uVar5 >> 0x10);
  puVar12[4] = (char)uVar4;
  puVar12[6] = (char)((uint)uVar6 >> 0x10);
  puVar12[7] = (char)((uint)uVar6 >> 0x18);
  *(ezb_shortaddr_t *)(puVar12 + 8) = shortaddr;
  addr_table_lru_update(tbl_00,(nwk_addr_ref_t)uVar7);
_L0:
  iVar9 = *(int *)(iVar9 + 0xc50) + uVar7 * 0x12;
  *(byte *)(iVar9 + 0x11) = *(byte *)(iVar9 + 0x11) & 0xfe;
  *ref_p = (nwk_addr_ref_t)uVar7;
  return 0;
}

