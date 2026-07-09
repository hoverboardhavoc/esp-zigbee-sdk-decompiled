/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> scene_table_add_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 scene_table_add_entry(undefined4 param_1,byte *param_2,int param_3)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  
  pbVar2 = (byte *)scene_table_get();
  pbVar4 = pbVar2 + 8;
  uVar1 = 0;
  while( true ) {
    if ((uint)*pbVar2 <= (uVar1 & 0xff)) {
      return 0;
    }
    if (param_2 == pbVar4) break;
    pbVar4 = pbVar4 + 0x20;
    uVar1 = uVar1 + 1;
  }
  if ((param_3 != 0) && (iVar3 = scene_table_store_scene(param_1), iVar3 != 0)) {
    return 0;
  }
  if (pbVar2[uVar1 * 0x20 + 8] == 0) {
    **(char **)(pbVar2 + 4) = **(char **)(pbVar2 + 4) + '\x01';
    pbVar2[uVar1 * 0x20 + 8] = 1;
  }
  return 1;
}

