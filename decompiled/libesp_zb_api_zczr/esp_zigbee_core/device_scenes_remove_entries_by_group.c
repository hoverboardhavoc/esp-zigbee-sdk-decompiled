/*
 * Last changed at upstream commit 3ee1c52790580ff8c3ec33b61f57334e0f637dc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/3ee1c52790580ff8c3ec33b61f57334e0f637dc8
 * Upstream date: 2023-05-26 18:12:14 +0800
 * Upstream subject: esp-zboss: Provide zboss APIs to fix github issues(70cea8e)
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
      device_scene_free_fields((&DAT_00012348)[uVar1 * 3]);
    }
  }
  return;
}

