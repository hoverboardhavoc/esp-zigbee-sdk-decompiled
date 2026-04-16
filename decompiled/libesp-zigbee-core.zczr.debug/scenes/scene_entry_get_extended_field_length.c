/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_entry_get_extended_field_length
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t scene_entry_get_extended_field_length(zcl_scene_table_entry_t *entry)

{
  ezb_zcl_scenes_extension_field_t *field;
  uint16_t uVar1;
  
  uVar1 = 0;
  for (field = entry->extension_field; field != (ezb_zcl_scenes_extension_field_t *)0x0;
      field = field->next) {
    uVar1 = field->length + uVar1 + 3;
  }
  return uVar1;
}

