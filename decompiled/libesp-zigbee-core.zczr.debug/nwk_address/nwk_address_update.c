/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_address_update(int *param_1,uint param_2,undefined2 *param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  undefined1 *puVar13;
  uint uVar14;
  
  iVar6 = core_globals_get();
  iVar5 = iVar6 + 0xc4c;
  if (param_2 < 0xfff8) {
    if (param_1 == (int *)0x0) {
      uVar9 = 2;
    }
    else if (*param_1 == 0 && param_1[1] == 0) {
      uVar9 = 2;
    }
    else if ((*param_1 == -1) && (param_1[1] == -1)) {
      uVar9 = 2;
    }
    else {
      uVar7 = search_short(iVar5,param_2);
      uVar14 = (uint)*(ushort *)(iVar6 + 0xc54);
      uVar8 = search_extended(iVar5,param_1);
      uVar11 = (uint)*(ushort *)(iVar6 + 0xc54);
      uVar10 = uVar7;
      if ((uVar7 < uVar14) && (uVar8 < uVar11)) {
        if (uVar7 != uVar8) {
          piVar12 = (int *)(uVar7 * 0x12 + *(int *)(iVar6 + 0xc50));
          if ((*piVar12 != 0 || piVar12[1] != 0) && ((*piVar12 != -1 || (piVar12[1] != -1)))) {
            *(byte *)((int)piVar12 + 0x11) = *(byte *)((int)piVar12 + 0x11) | 1;
            return 0xd;
          }
          if (*(byte *)(piVar12 + 4) == 0) {
            nwk_address_delete(uVar7);
            uVar10 = uVar8;
          }
          else {
            bVar1 = *(byte *)(*(int *)(iVar6 + 0xc50) + uVar8 * 0x12 + 0x10);
            if (bVar1 == 0) {
              nwk_address_delete(uVar8);
            }
            else if (bVar1 < *(byte *)(piVar12 + 4)) {
              addr_table_ref_redirect(iVar5,uVar8,uVar7);
            }
            else {
              addr_table_ref_redirect(iVar5,uVar7,uVar8);
              uVar10 = uVar8;
            }
          }
        }
      }
      else {
        uVar10 = uVar8;
        if ((uVar11 <= uVar8) && (uVar10 = uVar7, uVar7 < uVar14)) {
          piVar12 = (int *)(*(int *)(iVar6 + 0xc50) + uVar7 * 0x12);
          if ((*piVar12 != 0 || piVar12[1] != 0) && ((*piVar12 != -1 || (piVar12[1] != -1)))) {
            *(byte *)((int)piVar12 + 0x11) = *(byte *)((int)piVar12 + 0x11) | 1;
            return 0xd;
          }
        }
      }
      if (uVar7 < uVar14 || uVar8 < uVar11) {
        puVar13 = (undefined1 *)(*(int *)(iVar6 + 0xc50) + uVar10 * 0x12);
        iVar2 = *param_1;
        iVar4 = param_1[1];
        iVar3 = param_1[1];
        *puVar13 = (char)(short)*param_1;
        puVar13[1] = (char)((uint)iVar2 >> 8);
        puVar13[2] = (char)((uint)iVar2 >> 0x10);
        puVar13[3] = (char)((uint)iVar2 >> 0x18);
        puVar13[4] = (char)(short)iVar4;
        puVar13[5] = (char)((uint)iVar3 >> 8);
        puVar13[6] = (char)((uint)iVar3 >> 0x10);
        puVar13[7] = (char)((uint)iVar3 >> 0x18);
        *(short *)(puVar13 + 8) = (short)param_2;
        addr_table_lru_update(iVar5,uVar10);
      }
      else {
        uVar10 = addr_table_add(iVar5,param_2,param_1);
      }
      iVar5 = uVar10 * 0x12 + *(int *)(iVar6 + 0xc50);
      *(byte *)(iVar5 + 0x11) = *(byte *)(iVar5 + 0x11) & 0xfe;
      *param_3 = (short)uVar10;
      uVar9 = 0;
    }
  }
  else {
    uVar9 = 2;
  }
  return uVar9;
}

