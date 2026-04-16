/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_disc_table.o -> nwk_disc_table_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_potential_parent_t * nwk_disc_table_next(nwk_potential_parent_t *parent)

{
  int iVar1;
  nwk_potential_parent_t *pnVar2;
  uint uVar3;
  
  iVar1 = core_globals_get();
  if (parent == (nwk_potential_parent_t *)0x0) {
    uVar3 = 0xffff;
  }
  else {
    uVar3 = ((int)parent - (iVar1 + 0xb2c) >> 2) * -0x33333333 & 0xffff;
  }
  uVar3 = bitmap_find_next_bit(iVar1 + 0xba4,6,uVar3 + 1 & 0xffff);
  if (uVar3 < 6) {
    pnVar2 = (nwk_potential_parent_t *)(iVar1 + 0xb2c + uVar3 * 0x14);
  }
  else {
    pnVar2 = (nwk_potential_parent_t *)0x0;
  }
  return pnVar2;
}

