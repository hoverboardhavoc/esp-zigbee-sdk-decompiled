/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_remove_stored_scene
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void scene_table_remove_stored_scene(uint param_1,uint param_2,uint param_3)

{
  undefined4 uStack_1c;
  undefined4 uStack_18;
  byte *pbStack_14;
  
  uStack_1c = 0;
  uStack_18 = 0;
  pbStack_14 = (byte *)0x0;
  ds_zcl_scene_info_iterator_init(&uStack_1c);
  do {
    if ((char)uStack_18 != '\0') {
_L0:
      ds_zcl_scene_info_iterator_deinit(&uStack_1c);
      return;
    }
    if (*pbStack_14 == param_1) {
      if ((*(ushort *)(pbStack_14 + 1) == param_2) && (pbStack_14[3] == param_3)) {
        ds_zcl_scene_info_delete(&uStack_1c);
        goto _L0;
      }
    }
    ds_zcl_scene_info_next(&uStack_1c);
  } while( true );
}

