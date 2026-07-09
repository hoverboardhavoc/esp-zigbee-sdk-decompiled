/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void scene_table_deinit(undefined4 param_1)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar3 = scenes_srv_get_attr_desc(0xeff1);
  if (iVar3 != 0) {
    pbVar2 = *(byte **)(iVar3 + 8);
    if (pbVar2 != (byte *)0x0) {
      for (uVar1 = 0; uVar1 < *pbVar2; uVar1 = uVar1 + 1 & 0xff) {
        scene_table_remove_entry(param_1,pbVar2 + uVar1 * 0x20 + 8);
      }
      mm_free(pbVar2);
    }
    *(undefined4 *)(iVar3 + 8) = 0;
  }
  return;
}

