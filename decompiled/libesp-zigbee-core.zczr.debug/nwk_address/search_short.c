/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> search_short
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void search_short(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  while( true ) {
    uVar1 = bitmap_find_next_bit(*param_1,*(undefined2 *)(param_1 + 2),uVar1);
    if (*(ushort *)(param_1 + 2) <= uVar1) {
      return;
    }
    iVar2 = param_1[1] + uVar1 * 0x12;
    if (((*(ushort *)(iVar2 + 0x10) >> 10 & 1) == 0) && (*(ushort *)(iVar2 + 8) == param_2)) break;
    uVar1 = uVar1 + 1 & 0xffff;
  }
  return;
}

