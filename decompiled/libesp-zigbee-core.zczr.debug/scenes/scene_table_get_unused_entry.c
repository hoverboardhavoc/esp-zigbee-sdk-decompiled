/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_get_unused_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte * scene_table_get_unused_entry(void)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  
  pbVar2 = (byte *)scene_table_get();
  if (pbVar2 != (byte *)0x0) {
    for (uVar1 = 0; uVar1 < *pbVar2; uVar1 = uVar1 + 1 & 0xff) {
      iVar3 = scene_entry_is_used(pbVar2 + uVar1 * 0x20 + 8);
      if (iVar3 == 0) {
        return pbVar2 + uVar1 * 0x20 + 8;
      }
    }
  }
  return (byte *)0x0;
}

