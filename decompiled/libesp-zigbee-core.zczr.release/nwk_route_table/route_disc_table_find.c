/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> route_disc_table_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort * route_disc_table_find(int *param_1,uint param_2,uint param_3)

{
  ushort *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    uVar2 = bitmap_find_next_bit(param_1[1],(short)param_1[2],uVar2);
    if (*(ushort *)(param_1 + 2) <= uVar2) {
      return (ushort *)0x0;
    }
    puVar1 = (ushort *)(*param_1 + uVar2 * 0x10);
    if ((*puVar1 == param_2) && ((byte)puVar1[5] == param_3)) break;
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return puVar1;
}

