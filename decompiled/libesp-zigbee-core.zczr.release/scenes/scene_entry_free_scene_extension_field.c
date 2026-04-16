/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> scene_entry_free_scene_extension_field
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void scene_entry_free_scene_extension_field(zcl_scene_table_entry_t *entry)

{
  ezb_zcl_scenes_extension_field_t *peVar1;
  ezb_zcl_scenes_extension_field_s *peVar2;
  
  if (entry != (zcl_scene_table_entry_t *)0x0) {
    peVar1 = entry->extension_field;
    if (entry->extension_field != (ezb_zcl_scenes_extension_field_t *)0x0) {
      do {
        peVar2 = peVar1->next;
        if (peVar1->value != (uint8_t *)0x0) {
          mm_free();
        }
        peVar1->length = '\0';
        mm_free(peVar1);
        peVar1 = peVar2;
      } while (peVar2 != (ezb_zcl_scenes_extension_field_s *)0x0);
      entry->extension_field = (ezb_zcl_scenes_extension_field_t *)0x0;
    }
    return;
  }
  return;
}

