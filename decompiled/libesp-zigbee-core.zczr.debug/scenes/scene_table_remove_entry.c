/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_remove_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int scene_table_remove_entry(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  uint extraout_a1;
  char *pcVar6;
  
  iVar2 = scene_table_get();
  iVar3 = iVar2;
  if ((param_2 != 0) && (iVar3 = scene_entry_is_used(param_2), iVar3 != 0)) {
    scene_table_remove_stored_scene
              (param_1,*(undefined2 *)(param_2 + 2),*(undefined1 *)(param_2 + 4));
    iVar3 = scene_entry_set_unused(param_2);
    pcVar6 = *(char **)(iVar2 + 4);
    if ((pcVar6 == (char *)0x0) || (*pcVar6 == '\0')) {
      uVar4 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/scenes.c",
                            0x16c,"scene_table_remove_entry",
                            "(scene_table->count && *scene_table->count >= 1)");
      pbVar5 = (byte *)scene_table_get();
      if (pbVar5 == (byte *)0x0) {
        iVar3 = 0x8b;
      }
      else {
        for (uVar1 = 0; uVar1 < *pbVar5; uVar1 = uVar1 + 1 & 0xff) {
          if (*(ushort *)(pbVar5 + uVar1 * 0x20 + 10) == extraout_a1) {
            scene_table_remove_entry(uVar4,pbVar5 + uVar1 * 0x20 + 8);
          }
        }
        iVar3 = 0;
      }
      return iVar3;
    }
    *pcVar6 = *pcVar6 + -1;
  }
  return iVar3;
}

