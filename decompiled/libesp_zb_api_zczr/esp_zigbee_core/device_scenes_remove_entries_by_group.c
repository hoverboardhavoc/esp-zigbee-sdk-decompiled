/*
 * Last changed at upstream commit 1f6b611e278a00f885edde9cb38294c3c08373a5
 * https://github.com/espressif/esp-zigbee-sdk/commit/1f6b611e278a00f885edde9cb38294c3c08373a5
 * Upstream date: 2023-08-01 20:17:41 +0800
 * Upstream subject: esp-zigbee-sdk: fix zigbee zcl scenes extension field implementation
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> device_scenes_remove_entries_by_group
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scenes_remove_entries_by_group(uint param_1)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < 10; uVar1 = uVar1 + 1 & 0xff) {
    if ((ushort)(&esp_zb_zcl_scenes_table)[uVar1 * 6] == param_1) {
      (&esp_zb_zcl_scenes_table)[uVar1 * 6] = 0xffff;
      device_scene_free_fields((&DAT_000137ac)[uVar1 * 3]);
      (&DAT_000137ac)[uVar1 * 3] = 0;
    }
  }
  return;
}

