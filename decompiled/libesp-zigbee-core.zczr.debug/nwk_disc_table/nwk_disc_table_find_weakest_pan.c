/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_disc_table.o -> nwk_disc_table_find_weakest_pan
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
  undefined3 in_register_00002029;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  bitmap_t abStack_24 [4];
  bitmap_t pan_ref_in_use [2];
  uint8_t max_lqa [16];
  
  uVar2 = CONCAT31(in_register_00002029,min_lqa);
  iVar3 = core_globals_get();
  _pan_ref_in_use = 0;
  abStack_24[0] = '\0';
  abStack_24[1] = '\0';
  uVar5 = 0;
  while( true ) {
    uVar5 = bitmap_find_next_bit(iVar3 + 0xba4,6,uVar5);
    if (5 < uVar5) break;
    uVar4 = (uint)*(byte *)(uVar5 * 0x14 + iVar3 + 0x1000 + -0x4cc);
    bVar1 = *(byte *)(iVar3 + 0x1000 + uVar5 * 0x14 + -0x4cb);
    bVar6 = pan_ref_in_use[uVar4];
    if (pan_ref_in_use[uVar4] < bVar1) {
      bVar6 = bVar1;
    }
    pan_ref_in_use[uVar4] = bVar6;
    test_and_set_bitmap(uVar4,abStack_24);
    uVar5 = uVar5 + 1 & 0xffff;
  }
  uVar5 = 0xff;
  uVar4 = 0;
  while( true ) {
    uVar4 = bitmap_find_next_bit(abStack_24,0x10,uVar4);
    uVar4 = uVar4 & 0xff;
    if (0xf < uVar4) break;
    if (pan_ref_in_use[uVar4] < uVar2) {
      uVar5 = uVar4;
      uVar2 = (uint)pan_ref_in_use[uVar4];
    }
    uVar4 = uVar4 + 1 & 0xff;
  }
  return (nwk_panid_ref_t)uVar5;
}

