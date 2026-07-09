/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> scene_table_remove_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void scene_table_remove_entry(undefined4 param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  char cVar3;
  
  iVar1 = scene_table_get();
  cVar3 = *param_2;
  if (cVar3 != '\0') {
    scene_table_remove_stored_scene(param_1,*(undefined2 *)(param_2 + 2),param_2[4]);
    scene_entry_set_unused(param_2);
    pcVar2 = *(char **)(iVar1 + 4);
    if ((pcVar2 == (char *)0x0) || (cVar3 = *pcVar2, cVar3 == '\0')) {
      __assert_func(0,0,0,0);
    }
    *pcVar2 = cVar3 + -1;
  }
  return;
}

