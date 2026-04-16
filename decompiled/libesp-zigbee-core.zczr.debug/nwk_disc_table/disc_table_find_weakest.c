/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_disc_table.o -> disc_table_find_weakest
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_disc_table_ent_t * disc_table_find_weakest(uint8_t min_lqa)

{
  nwk_disc_table_ent_t *pnVar1;
  undefined3 in_register_00002029;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = CONCAT31(in_register_00002029,min_lqa);
  iVar3 = core_globals_get();
  uVar4 = 0;
  pnVar1 = (nwk_disc_table_ent_t *)0x0;
  while( true ) {
    uVar4 = bitmap_find_next_bit(iVar3 + 0xba4,6,uVar4);
    uVar4 = uVar4 & 0xff;
    if (5 < uVar4) break;
    uVar5 = (uint)*(byte *)(iVar3 + uVar4 * 0x14 + 0xb35);
    if (uVar5 < uVar2) {
      pnVar1 = (nwk_disc_table_ent_t *)(iVar3 + 0xb2c + uVar4 * 0x14);
      uVar2 = uVar5;
    }
    uVar4 = uVar4 + 1 & 0xff;
  }
  return pnVar1;
}

