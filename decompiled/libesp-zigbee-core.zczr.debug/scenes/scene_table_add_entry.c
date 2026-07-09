/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_add_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool scene_table_add_entry(undefined4 param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  pbVar1 = (byte *)scene_table_get();
  uVar3 = 0;
  while( true ) {
    if (*pbVar1 <= uVar3) {
      return false;
    }
    if (pbVar1 + uVar3 * 0x20 + 8 == param_2) break;
    uVar3 = uVar3 + 1 & 0xff;
  }
  if (param_3 == 0) {
    bVar4 = true;
  }
  else {
    iVar2 = scene_table_store_scene(param_1,param_2);
    bVar4 = iVar2 == 0;
    if (iVar2 != 0) {
      return bVar4;
    }
  }
  iVar2 = scene_entry_is_used(pbVar1 + uVar3 * 0x20 + 8);
  if (iVar2 != 0) {
    return bVar4;
  }
  **(char **)(pbVar1 + 4) = **(char **)(pbVar1 + 4) + '\x01';
  pbVar1[uVar3 * 0x20 + 8] = 1;
  return bVar4;
}

