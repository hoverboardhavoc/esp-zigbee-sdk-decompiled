/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> scene_table_remove_all_associated_scene
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 scene_table_remove_all_associated_scene(undefined4 param_1,uint param_2)

{
  uint uVar1;
  byte *pbVar2;
  undefined4 uVar3;
  
  pbVar2 = (byte *)scene_table_get();
  if (pbVar2 == (byte *)0x0) {
    uVar3 = 0x8b;
  }
  else {
    for (uVar1 = 0; uVar1 < *pbVar2; uVar1 = uVar1 + 1 & 0xff) {
      if (*(ushort *)(pbVar2 + uVar1 * 0x20 + 10) == param_2) {
        scene_table_remove_entry(param_1,pbVar2 + uVar1 * 0x20 + 8);
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}

