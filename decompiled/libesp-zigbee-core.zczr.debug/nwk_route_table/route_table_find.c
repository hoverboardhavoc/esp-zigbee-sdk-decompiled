/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> route_table_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort * route_table_find(int *param_1,uint param_2)

{
  uint uVar1;
  ushort *puVar2;
  
  uVar1 = 0;
  while( true ) {
    uVar1 = bitmap_find_next_bit(param_1[1],(short)param_1[2],uVar1);
    if (*(ushort *)(param_1 + 2) <= uVar1) {
      return (ushort *)0x0;
    }
    puVar2 = (ushort *)(*param_1 + uVar1 * 0x10);
    if (*puVar2 == param_2) break;
    uVar1 = uVar1 + 1 & 0xffff;
  }
  return puVar2;
}

