/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_disc_table.o -> nwk_disc_table_find_weakest_pan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nwk_disc_table_find_weakest_pan(uint param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  int iVar9;
  undefined2 auStack_34 [2];
  byte abStack_30 [16];
  
  iVar5 = core_globals_get();
  abStack_30[0] = 0;
  abStack_30[1] = 0;
  abStack_30[2] = 0;
  abStack_30[3] = 0;
  abStack_30[4] = 0;
  abStack_30[5] = 0;
  abStack_30[6] = 0;
  abStack_30[7] = 0;
  abStack_30[8] = 0;
  abStack_30[9] = 0;
  abStack_30[10] = 0;
  abStack_30[0xb] = 0;
  abStack_30[0xc] = 0;
  abStack_30[0xd] = 0;
  abStack_30[0xe] = 0;
  abStack_30[0xf] = 0;
  auStack_34[0] = 0;
  uVar6 = 0;
  while (uVar6 = bitmap_find_next_bit(iVar5 + 0xba4,6,uVar6), uVar6 < 6) {
    iVar9 = uVar6 * 0x14 + iVar5;
    bVar1 = *(byte *)(iVar9 + 0xb34);
    bVar2 = *(byte *)(iVar9 + 0xb35);
    bVar8 = abStack_30[bVar1];
    if (abStack_30[bVar1] < bVar2) {
      bVar8 = bVar2;
    }
    abStack_30[bVar1] = bVar8;
    test_and_set_bitmap_isra_0(auStack_34);
    uVar6 = uVar6 + 1 & 0xffff;
  }
  uVar7 = 0;
  uVar6 = 0xff;
  while( true ) {
    uVar7 = bitmap_find_next_bit(auStack_34,0x10,uVar7);
    uVar7 = uVar7 & 0xff;
    if (0xf < uVar7) break;
    uVar4 = uVar7;
    uVar3 = (uint)abStack_30[uVar7];
    if (param_1 <= abStack_30[uVar7]) {
      uVar4 = uVar6;
      uVar3 = param_1;
    }
    param_1 = uVar3;
    uVar7 = uVar7 + 1 & 0xff;
    uVar6 = uVar4;
  }
  return uVar6;
}

