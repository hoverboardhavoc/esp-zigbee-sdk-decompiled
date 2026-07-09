/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> scene_table_get_unused_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte * scene_table_get_unused_entry(void)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  
  pbVar3 = (byte *)scene_table_get();
  if (pbVar3 != (byte *)0x0) {
    pbVar4 = pbVar3 + 8;
    uVar2 = 0;
    do {
      uVar5 = uVar2;
      if ((uint)*pbVar3 <= (uVar5 & 0xff)) {
        return (byte *)0x0;
      }
      bVar1 = *pbVar4;
      pbVar4 = pbVar4 + 0x20;
      uVar2 = uVar5 + 1;
    } while (bVar1 != 0);
    pbVar3 = pbVar3 + uVar5 * 0x20 + 8;
  }
  return pbVar3;
}

