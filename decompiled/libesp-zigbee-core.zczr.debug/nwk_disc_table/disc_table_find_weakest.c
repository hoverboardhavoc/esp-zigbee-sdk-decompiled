/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_disc_table.o -> disc_table_find_weakest
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int disc_table_find_weakest(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = core_globals_get();
  uVar3 = 0;
  iVar1 = 0;
  while( true ) {
    uVar3 = bitmap_find_next_bit(iVar2 + 0xba4,6,uVar3);
    uVar3 = uVar3 & 0xff;
    if (5 < uVar3) break;
    uVar4 = (uint)*(byte *)(iVar2 + uVar3 * 0x14 + 0xb35);
    if (uVar4 < param_1) {
      iVar1 = iVar2 + 0xb2c + uVar3 * 0x14;
      param_1 = uVar4;
    }
    uVar3 = uVar3 + 1 & 0xff;
  }
  return iVar1;
}

