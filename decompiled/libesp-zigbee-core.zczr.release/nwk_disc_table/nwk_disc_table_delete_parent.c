/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_disc_table.o -> nwk_disc_table_delete_parent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_disc_table_delete_parent(nwk_potential_parent_t *parent)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = core_globals_get();
  iVar3 = iVar3 + 0xb2c;
  uVar4 = ((int)parent - iVar3 >> 2) * -0x33333333;
  if ((uVar4 & 0xffff) < 6) goto _L0;
  do {
    iVar3 = __assert_func(0,0,0,0);
_L0:
    uVar1 = 1 << (uVar4 & 7) & 0xff;
    uVar4 = (uVar4 << 0x10) >> 0x13;
    uVar2 = __atomic_fetch_and_1(iVar3 + 0x78 + uVar4,~uVar1 & 0xff);
  } while ((uVar1 & uVar2) == 0);
  return;
}

