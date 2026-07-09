/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_disc_table.o -> disc_table_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int disc_table_find(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  while( true ) {
    uVar3 = bitmap_find_next_bit(param_1 + 0x78,6,uVar3);
    if (5 < uVar3) {
      return 0;
    }
    iVar1 = uVar3 * 0x14 + param_1;
    iVar2 = disc_table_ent_match(iVar1,param_2,param_3,param_4);
    if (iVar2 != 0) break;
    uVar3 = uVar3 + 1 & 0xffff;
  }
  return iVar1;
}

