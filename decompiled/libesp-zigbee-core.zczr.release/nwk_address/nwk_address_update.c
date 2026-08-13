/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_address_update(undefined4 *param_1,uint param_2,undefined2 *param_3)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined1 *puVar11;
  int iVar12;
  int iVar13;
  
  iVar6 = core_globals_get();
  if (0xfff7 < param_2) {
    return 2;
  }
  if (param_1 == (undefined4 *)0x0) {
    return 2;
  }
  iVar7 = ezb_eui64_is_invalid(param_1);
  if (iVar7 != 0) {
    return 2;
  }
  iVar7 = iVar6 + 0xc4c;
  uVar8 = search_short(iVar7,param_2);
  uVar2 = *(ushort *)(iVar6 + 0xc54);
  uVar9 = search_extended(iVar7,param_1);
  if (uVar8 < uVar2) {
    iVar12 = *(int *)(iVar6 + 0xc50);
    if (uVar9 < *(ushort *)(iVar6 + 0xc54)) {
      if (uVar8 != uVar9) {
        iVar13 = uVar8 * 0x12 + iVar12;
        iVar10 = ezb_eui64_is_invalid(iVar13);
        if (iVar10 == 0) {
          *(byte *)(iVar13 + 0x11) = *(byte *)(iVar13 + 0x11) | 1;
          return 0xd;
        }
        if (*(byte *)(iVar13 + 0x10) == 0) {
          nwk_address_delete(uVar8);
        }
        else {
          bVar1 = *(byte *)(uVar9 * 0x12 + iVar12 + 0x10);
          if (bVar1 == 0) {
            nwk_address_delete(uVar9);
            uVar9 = uVar8;
          }
          else if (bVar1 < *(byte *)(iVar13 + 0x10)) {
            addr_table_ref_redirect_isra_0(iVar12,uVar9,uVar8);
            uVar9 = uVar8;
          }
          else {
            addr_table_ref_redirect_isra_0(iVar12,uVar8,uVar9);
          }
        }
      }
    }
    else {
      iVar12 = iVar12 + uVar8 * 0x12;
      iVar10 = ezb_eui64_is_invalid(iVar12);
      uVar9 = uVar8;
      if (iVar10 == 0) {
        *(byte *)(iVar12 + 0x11) = *(byte *)(iVar12 + 0x11) | 1;
        return 0xd;
      }
    }
  }
  else if (*(ushort *)(iVar6 + 0xc54) <= uVar9) {
    uVar9 = addr_table_add(iVar7,param_2,param_1);
    goto _L0;
  }
  puVar11 = (undefined1 *)(*(int *)(iVar6 + 0xc50) + uVar9 * 0x12);
  uVar3 = *(undefined2 *)(param_1 + 1);
  uVar4 = *param_1;
  uVar5 = param_1[1];
  *puVar11 = (char)*(undefined2 *)param_1;
  puVar11[1] = (char)((uint)uVar4 >> 8);
  puVar11[3] = (char)((uint)uVar4 >> 0x18);
  puVar11[5] = (char)((uint)uVar5 >> 8);
  puVar11[2] = (char)((uint)uVar4 >> 0x10);
  puVar11[4] = (char)uVar3;
  puVar11[6] = (char)((uint)uVar5 >> 0x10);
  puVar11[7] = (char)((uint)uVar5 >> 0x18);
  *(short *)(puVar11 + 8) = (short)param_2;
  addr_table_lru_update(iVar7,uVar9);
_L0:
  iVar6 = *(int *)(iVar6 + 0xc50) + uVar9 * 0x12;
  *(byte *)(iVar6 + 0x11) = *(byte *)(iVar6 + 0x11) & 0xfe;
  *param_3 = (short)uVar9;
  return 0;
}

