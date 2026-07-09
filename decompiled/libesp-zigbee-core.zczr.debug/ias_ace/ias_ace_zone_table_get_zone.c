/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_zone_table_get_zone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte * ias_ace_zone_table_get_zone(int *param_1,uint param_2)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if ((int)(uint)*(byte *)(param_1 + 1) <= iVar2) {
      return (byte *)0x0;
    }
    pbVar1 = (byte *)(*param_1 + iVar2 * 0x1e);
    if ((*(short *)(pbVar1 + 2) != -1) && (*pbVar1 == param_2)) break;
    iVar2 = iVar2 + 1;
  }
  return pbVar1;
}

