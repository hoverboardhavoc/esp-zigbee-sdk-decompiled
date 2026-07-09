/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> scene_table_find_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte * scene_table_find_entry(uint param_1,uint param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  uint uVar3;
  
  pbVar1 = (byte *)scene_table_get();
  if (pbVar1 != (byte *)0x0) {
    pbVar2 = pbVar1 + 8;
    for (uVar3 = 0; (uVar3 & 0xff) < (uint)*pbVar1; uVar3 = uVar3 + 1) {
      if (((*pbVar2 != 0) && (*(ushort *)(pbVar2 + 2) == param_1)) && (pbVar2[4] == param_2)) {
        return pbVar1 + uVar3 * 0x20 + 8;
      }
      pbVar2 = pbVar2 + 0x20;
    }
    pbVar1 = (byte *)0x0;
  }
  return pbVar1;
}

