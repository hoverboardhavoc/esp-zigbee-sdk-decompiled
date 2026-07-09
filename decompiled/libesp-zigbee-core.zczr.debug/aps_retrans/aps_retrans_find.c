/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_retrans_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_retrans_find(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    uVar1 = bitmap_find_next_bit(param_1 + 0x41c,0x20,uVar1);
    uVar1 = uVar1 & 0xff;
    if (0x1f < uVar1) {
      return 0;
    }
    if ((*(byte *)(uVar1 * 0x20 + param_1 + 0x22) == param_3) &&
       (*(ushort *)(uVar1 * 0x20 + param_1 + 0x20) == param_2)) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return uVar1 * 0x20 + param_1 + 0x1c;
}

