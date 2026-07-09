/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_link_mngr.o -> nwk_ls_heap_shift_down.constprop.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_ls_heap_shift_down_constprop_0(int param_1,uint param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  undefined2 *puVar6;
  int iVar7;
  uint uVar8;
  
  uVar5 = 0;
  do {
    iVar7 = (uVar5 & 0x7f) * 2;
    uVar3 = iVar7 + 1U & 0xff;
    uVar8 = iVar7 + 2U & 0xff;
    if ((uVar3 < param_2) && (*(ushort *)(uVar5 * 4 + param_1) < *(ushort *)(uVar3 * 4 + param_1)))
    {
      if (uVar8 < param_2) goto _L0;
_L0:
      uVar8 = uVar3;
    }
    else {
      uVar3 = uVar5;
      if (param_2 <= uVar8) {
        return;
      }
_L0:
      if (*(ushort *)(uVar8 * 4 + param_1) <= *(ushort *)(uVar3 * 4 + param_1)) goto _L0;
    }
    if (uVar5 == uVar8) {
      return;
    }
    puVar4 = (undefined2 *)(uVar8 * 4 + param_1);
    puVar6 = (undefined2 *)(uVar5 * 4 + param_1);
    uVar2 = *puVar6;
    *puVar6 = *puVar4;
    uVar1 = *(undefined1 *)(puVar6 + 1);
    puVar6[1] = puVar4[1];
    *puVar4 = uVar2;
    *(undefined1 *)(puVar4 + 1) = uVar1;
    uVar5 = uVar8;
  } while( true );
}

