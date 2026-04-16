/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_disc_table.o -> nwk_disc_table_find_weakest_pan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: max_lqa */
/* WARNING: Unknown calling convention */

nwk_panid_ref_t nwk_disc_table_find_weakest_pan(uint8_t min_lqa)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined3 in_register_00002029;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  int iVar9;
  bitmap_t abStack_34 [4];
  bitmap_t pan_ref_in_use [2];
  uint8_t max_lqa [16];
  
  uVar4 = CONCAT31(in_register_00002029,min_lqa);
  iVar5 = core_globals_get();
  _pan_ref_in_use = 0;
  abStack_34[0] = '\0';
  abStack_34[1] = '\0';
  uVar6 = 0;
  while (uVar6 = bitmap_find_next_bit(iVar5 + 0xba4,6,uVar6), uVar6 < 6) {
    iVar9 = uVar6 * 0x14 + iVar5;
    uVar7 = (uint)*(byte *)(iVar9 + 0xb34);
    bVar1 = *(byte *)(iVar9 + 0xb35);
    bVar8 = pan_ref_in_use[uVar7];
    if (pan_ref_in_use[uVar7] < bVar1) {
      bVar8 = bVar1;
    }
    pan_ref_in_use[uVar7] = bVar8;
    test_and_set_bitmap(uVar7,abStack_34);
    uVar6 = uVar6 + 1 & 0xffff;
  }
  uVar7 = 0;
  uVar6 = 0xff;
  while( true ) {
    uVar7 = bitmap_find_next_bit(abStack_34,0x10,uVar7);
    uVar7 = uVar7 & 0xff;
    if (0xf < uVar7) break;
    uVar3 = uVar7;
    uVar2 = (uint)pan_ref_in_use[uVar7];
    if (uVar4 <= pan_ref_in_use[uVar7]) {
      uVar3 = uVar6;
      uVar2 = uVar4;
    }
    uVar4 = uVar2;
    uVar7 = uVar7 + 1 & 0xff;
    uVar6 = uVar3;
  }
  return (nwk_panid_ref_t)uVar6;
}

