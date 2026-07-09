/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_find_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte * scene_table_find_entry(uint param_1,uint param_2)

{
  byte *pbVar1;
  uint uVar2;
  
  pbVar1 = (byte *)scene_table_get();
  if (pbVar1 != (byte *)0x0) {
    for (uVar2 = 0; uVar2 < *pbVar1; uVar2 = uVar2 + 1 & 0xff) {
      if (((pbVar1[uVar2 * 0x20 + 8] != 0) && (*(ushort *)(pbVar1 + uVar2 * 0x20 + 10) == param_1))
         && (pbVar1[uVar2 * 0x20 + 0xc] == param_2)) {
        return pbVar1 + uVar2 * 0x20 + 8;
      }
    }
    pbVar1 = (byte *)0x0;
  }
  return pbVar1;
}

