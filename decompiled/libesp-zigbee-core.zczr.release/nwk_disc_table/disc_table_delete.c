/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_disc_table.o -> disc_table_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void disc_table_delete(nwk_disc_table_t *tbl,nwk_disc_table_ent_t *ent)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = ((int)ent - (int)tbl >> 2) * -0x33333333;
  if ((uVar3 & 0xffff) < 6) goto _L0;
  do {
    tbl = (nwk_disc_table_t *)__assert_func(0,0,0,0);
_L0:
    uVar1 = 1 << (uVar3 & 7) & 0xff;
    uVar3 = (uVar3 << 0x10) >> 0x13;
    uVar2 = __atomic_fetch_and_1(tbl->ent_in_use + uVar3,~uVar1 & 0xff);
  } while ((uVar1 & uVar2) == 0);
  return;
}

