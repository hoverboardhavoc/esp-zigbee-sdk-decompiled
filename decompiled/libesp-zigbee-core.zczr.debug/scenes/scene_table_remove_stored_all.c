/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_remove_stored_all
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void scene_table_remove_stored_all(uint param_1)

{
  undefined1 auStack_1c [4];
  char cStack_18;
  byte *pbStack_14;
  
  ds_zcl_scene_info_iterator_init(auStack_1c);
  while (cStack_18 == '\0') {
    if (*pbStack_14 == param_1) {
      ds_zcl_scene_info_delete(auStack_1c);
      ds_zcl_scene_info_read(auStack_1c);
    }
    else {
      ds_zcl_scene_info_next(auStack_1c);
    }
  }
  return;
}

