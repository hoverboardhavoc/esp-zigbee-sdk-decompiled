/*
 * Last changed at upstream commit dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * https://github.com/espressif/esp-zigbee-sdk/commit/dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * Upstream date: 2022-12-14 19:24:05 +0800
 * Upstream subject: examples:Add ota application example(986c075)
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
      device_scene_free_fields((&DAT_000122dc)[uVar1 * 3]);
    }
  }
  return;
}

