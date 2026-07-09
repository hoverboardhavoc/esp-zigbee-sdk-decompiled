/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_link_mngr.o -> nwk_ls_heap_shift_down
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_ls_heap_shift_down(int param_1,uint param_2,uint param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  while( true ) {
    uVar7 = (param_3 & 0x7f) * 2 + 1 & 0xff;
    uVar5 = (param_3 + 1) * 2 & 0xff;
    uVar6 = param_3;
    if ((uVar7 < param_2) &&
       (uVar6 = uVar7, *(ushort *)(uVar7 * 4 + param_1) <= *(ushort *)(param_3 * 4 + param_1))) {
      uVar6 = param_3;
    }
    if ((uVar5 < param_2) && (*(ushort *)(uVar6 * 4 + param_1) < *(ushort *)(uVar5 * 4 + param_1)))
    {
      uVar6 = uVar5;
    }
    if (param_3 == uVar6) break;
    puVar3 = (undefined2 *)(param_3 * 4 + param_1);
    uVar1 = *puVar3;
    uVar2 = puVar3[1];
    puVar4 = (undefined2 *)(uVar6 * 4 + param_1);
    *puVar3 = *puVar4;
    puVar3[1] = puVar4[1];
    *puVar4 = uVar1;
    puVar4[1] = uVar2;
    param_3 = uVar6;
  }
  return;
}

