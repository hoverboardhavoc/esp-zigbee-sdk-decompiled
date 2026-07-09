/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_disc_table.o -> nwk_disc_table_find_weakest_pan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nwk_disc_table_find_weakest_pan(uint param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  undefined2 auStack_24 [2];
  byte abStack_20 [16];
  
  iVar3 = core_globals_get();
  abStack_20[0] = 0;
  abStack_20[1] = 0;
  abStack_20[2] = 0;
  abStack_20[3] = 0;
  abStack_20[4] = 0;
  abStack_20[5] = 0;
  abStack_20[6] = 0;
  abStack_20[7] = 0;
  abStack_20[8] = 0;
  abStack_20[9] = 0;
  abStack_20[10] = 0;
  abStack_20[0xb] = 0;
  abStack_20[0xc] = 0;
  abStack_20[0xd] = 0;
  abStack_20[0xe] = 0;
  abStack_20[0xf] = 0;
  auStack_24[0] = 0;
  uVar4 = 0;
  while( true ) {
    uVar4 = bitmap_find_next_bit(iVar3 + 0xba4,6,uVar4);
    if (5 < uVar4) break;
    bVar1 = *(byte *)(uVar4 * 0x14 + iVar3 + 0x1000 + -0x4cc);
    bVar2 = *(byte *)(iVar3 + 0x1000 + uVar4 * 0x14 + -0x4cb);
    bVar6 = abStack_20[bVar1];
    if (abStack_20[bVar1] < bVar2) {
      bVar6 = bVar2;
    }
    abStack_20[bVar1] = bVar6;
    test_and_set_bitmap(auStack_24);
    uVar4 = uVar4 + 1 & 0xffff;
  }
  uVar4 = 0xff;
  uVar5 = 0;
  while( true ) {
    uVar5 = bitmap_find_next_bit(auStack_24,0x10,uVar5);
    uVar5 = uVar5 & 0xff;
    if (0xf < uVar5) break;
    if (abStack_20[uVar5] < param_1) {
      uVar4 = uVar5;
      param_1 = (uint)abStack_20[uVar5];
    }
    uVar5 = uVar5 + 1 & 0xff;
  }
  return uVar4;
}

