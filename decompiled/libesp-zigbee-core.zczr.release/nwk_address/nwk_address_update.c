/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_update
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
  uint uVar6;
  uint uVar7;
  int *piVar8;
  undefined1 *puVar9;
  int iVar10;
  int iVar11;
  
  iVar5 = core_globals_get();
  if (0xfff7 < param_2) {
    return 2;
  }
  if (param_1 == (int *)0x0) {
    return 2;
  }
  if ((param_1[1] + 1U == (uint)(*param_1 == 0)) && (0xfffffffd < *param_1 - 1U)) {
    return 2;
  }
  iVar11 = iVar5 + 0xc4c;
  uVar6 = search_short(iVar11,param_2);
  uVar2 = *(ushort *)(iVar5 + 0xc54);
  uVar7 = search_extended(iVar11,param_1);
  if (uVar6 < uVar2) {
    if ((uVar7 < *(ushort *)(iVar5 + 0xc54)) && (uVar6 != uVar7)) {
      iVar10 = *(int *)(iVar5 + 0xc50);
      piVar8 = (int *)(uVar6 * 0x12 + iVar10);
      if ((piVar8[1] + 1U != (uint)(*piVar8 == 0)) || (*piVar8 - 1U < 0xfffffffe)) {
        *(byte *)((int)piVar8 + 0x11) = *(byte *)((int)piVar8 + 0x11) | 1;
        return 0xd;
      }
      if (*(byte *)(piVar8 + 4) == 0) {
        nwk_address_delete(uVar6);
        uVar6 = uVar7;
      }
      else {
        bVar1 = *(byte *)(uVar7 * 0x12 + iVar10 + 0x10);
        if (bVar1 == 0) {
          nwk_address_delete();
        }
        else if (bVar1 < *(byte *)(piVar8 + 4)) {
          addr_table_ref_redirect_isra_0(iVar10,uVar7,uVar6);
        }
        else {
          addr_table_ref_redirect_isra_0(iVar10,uVar6,uVar7);
          uVar6 = uVar7;
        }
      }
    }
  }
  else {
    uVar6 = uVar7;
    if (*(ushort *)(iVar5 + 0xc54) <= uVar7) {
      uVar6 = addr_table_add(iVar11,param_2,param_1);
      goto _L0;
    }
  }
  puVar9 = (undefined1 *)(*(int *)(iVar5 + 0xc50) + uVar6 * 0x12);
  iVar4 = param_1[1];
  iVar10 = *param_1;
  iVar3 = param_1[1];
  *puVar9 = (char)(short)*param_1;
  puVar9[1] = (char)((uint)iVar10 >> 8);
  puVar9[3] = (char)((uint)iVar10 >> 0x18);
  puVar9[5] = (char)((uint)iVar3 >> 8);
  puVar9[2] = (char)((uint)iVar10 >> 0x10);
  puVar9[4] = (char)(short)iVar4;
  puVar9[6] = (char)((uint)iVar3 >> 0x10);
  puVar9[7] = (char)((uint)iVar3 >> 0x18);
  *(short *)(puVar9 + 8) = (short)param_2;
  addr_table_lru_update(iVar11,uVar6);
_L0:
  iVar5 = *(int *)(iVar5 + 0xc50) + uVar6 * 0x12;
  *(byte *)(iVar5 + 0x11) = *(byte *)(iVar5 + 0x11) & 0xfe;
  *param_3 = (short)uVar6;
  return 0;
}

