/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> search_extended
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void search_extended(undefined4 *param_1,int *param_2)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 0;
  do {
    uVar1 = bitmap_find_next_bit(*param_1,*(undefined2 *)(param_1 + 2),uVar1);
    if (*(ushort *)(param_1 + 2) <= uVar1) {
      return;
    }
    piVar2 = (int *)(param_1[1] + uVar1 * 0x12);
    if ((*(ushort *)(piVar2 + 4) >> 10 & 1) == 0) {
      if ((*param_2 == *piVar2) && (param_2[1] == piVar2[1])) {
        return;
      }
    }
    uVar1 = uVar1 + 1 & 0xffff;
  } while( true );
}

