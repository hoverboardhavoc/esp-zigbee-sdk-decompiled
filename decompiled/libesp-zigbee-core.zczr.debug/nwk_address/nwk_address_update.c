/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_address_update(int *param_1,uint param_2,undefined2 *param_3)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  undefined1 *puVar14;
  
  iVar7 = core_globals_get();
  iVar6 = iVar7 + 0xc4c;
  if (param_2 < 0xfff8) {
    if (param_1 == (int *)0x0) {
      uVar10 = 2;
    }
    else if (*param_1 == 0 && param_1[1] == 0) {
      uVar10 = 2;
    }
    else if ((*param_1 == -1) && (param_1[1] == -1)) {
      uVar10 = 2;
    }
    else {
      uVar8 = search_short(iVar6,param_2);
      uVar2 = *(ushort *)(iVar7 + 0xc54);
      uVar9 = search_extended(iVar6,param_1);
      uVar12 = (uint)*(ushort *)(iVar7 + 0xc54);
      uVar11 = uVar8;
      if ((uVar8 < uVar2) && (uVar9 < uVar12)) {
        if (uVar8 != uVar9) {
          piVar13 = (int *)(uVar8 * 0x12 + *(int *)(iVar7 + 0xc50));
          if ((*piVar13 != 0 || piVar13[1] != 0) && ((*piVar13 != -1 || (piVar13[1] != -1)))) {
            *(byte *)((int)piVar13 + 0x11) = *(byte *)((int)piVar13 + 0x11) | 1;
            return 0xd;
          }
          if (*(byte *)(piVar13 + 4) == 0) {
            nwk_address_delete(uVar8);
            uVar11 = uVar9;
          }
          else {
            bVar1 = *(byte *)(*(int *)(iVar7 + 0xc50) + uVar9 * 0x12 + 0x10);
            if (bVar1 == 0) {
              nwk_address_delete(uVar9);
            }
            else if (bVar1 < *(byte *)(piVar13 + 4)) {
              addr_table_ref_redirect(iVar6,uVar9,uVar8);
            }
            else {
              addr_table_ref_redirect(iVar6,uVar8,uVar9);
              uVar11 = uVar9;
            }
          }
        }
      }
      else {
        uVar11 = uVar9;
        if (uVar12 <= uVar9) {
          uVar11 = uVar8;
        }
      }
      if (uVar8 < uVar2 || uVar9 < uVar12) {
        puVar14 = (undefined1 *)(*(int *)(iVar7 + 0xc50) + uVar11 * 0x12);
        iVar3 = *param_1;
        iVar5 = param_1[1];
        iVar4 = param_1[1];
        *puVar14 = (char)(short)*param_1;
        puVar14[1] = (char)((uint)iVar3 >> 8);
        puVar14[2] = (char)((uint)iVar3 >> 0x10);
        puVar14[3] = (char)((uint)iVar3 >> 0x18);
        puVar14[4] = (char)(short)iVar5;
        puVar14[5] = (char)((uint)iVar4 >> 8);
        puVar14[6] = (char)((uint)iVar4 >> 0x10);
        puVar14[7] = (char)((uint)iVar4 >> 0x18);
        *(short *)(puVar14 + 8) = (short)param_2;
        addr_table_lru_update(iVar6,uVar11);
      }
      else {
        uVar11 = addr_table_add(iVar6,param_2,param_1);
      }
      iVar6 = uVar11 * 0x12 + *(int *)(iVar7 + 0xc50);
      *(byte *)(iVar6 + 0x11) = *(byte *)(iVar6 + 0x11) & 0xfe;
      *param_3 = (short)uVar11;
      uVar10 = 0;
    }
  }
  else {
    uVar10 = 2;
  }
  return uVar10;
}

