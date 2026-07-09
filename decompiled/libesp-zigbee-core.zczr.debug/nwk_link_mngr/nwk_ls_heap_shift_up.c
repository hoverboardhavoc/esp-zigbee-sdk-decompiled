/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_link_mngr.o -> nwk_ls_heap_shift_up
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_ls_heap_shift_up(int param_1,uint param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  uint uVar4;
  ushort *puVar5;
  
  while( true ) {
    if (param_2 == 0) {
      return;
    }
    uVar4 = (int)(param_2 - 1) / 2;
    puVar5 = (ushort *)((uVar4 & 0xff) * 4 + param_1);
    uVar2 = *puVar5;
    puVar3 = (ushort *)(param_2 * 4 + param_1);
    if (*puVar3 <= uVar2) break;
    uVar1 = puVar5[1];
    *puVar5 = *puVar3;
    puVar5[1] = puVar3[1];
    *puVar3 = uVar2;
    puVar3[1] = uVar1;
    param_2 = uVar4 & 0xff;
  }
  return;
}

