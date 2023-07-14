/*
 * Last changed at upstream commit 0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * https://github.com/espressif/esp-zigbee-sdk/commit/0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * Upstream date: 2023-07-14 11:30:10 +0800
 * Upstream subject: esp-zigbee-sdk: release v0.7.1(5785a2c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_device_callback_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_device_callback_entry(undefined4 param_1)

{
  uint *puVar1;
  uint uVar2;
  uint local_20;
  uint uStack_1c;
  uint uStack_18;
  
  puVar1 = (uint *)zb_buf_get_tail_func(0x38);
  uVar2 = *puVar1;
  puVar1[2] = 0;
  if (uVar2 == 0x54) {
    esp_zb_zcl_scenes_store_scene_cb(param_1,(char)puVar1[1]);
    return;
  }
  if (uVar2 < 0x55) {
    if (uVar2 == 0x1c) {
      zcl_process_ota_upgrade();
      puVar1[2] = 0;
      return;
    }
    if (uVar2 < 0x1d) {
      if (uVar2 == 7) {
        return;
      }
      if (uVar2 == 8) {
        esp_zb_zcl_ias_zone_enroll_response_cb(param_1);
        return;
      }
      if (uVar2 == 0) {
        local_20 = puVar1[3];
        uStack_1c = puVar1[4];
        uStack_18 = puVar1[5];
        zcl_device_attribute_update(0,&local_20);
        return;
      }
    }
    else {
      if (uVar2 == 0x53) {
        esp_zb_zcl_scenes_add_scene_cb(param_1);
        return;
      }
      if (uVar2 < 0x54) {
        if (uVar2 == 0x1d) {
          return;
        }
        if ((0x1c < uVar2) && (uVar2 - 0x24 < 4)) {
          return;
        }
      }
    }
  }
  else {
    if (uVar2 == 0x57) {
      esp_zb_zcl_scenes_remove_all_scenes_cb(param_1);
      return;
    }
    if (uVar2 < 0x58) {
      if (uVar2 == 0x55) {
        esp_zb_zcl_scenes_view_scene_cb(param_1);
        return;
      }
      if (uVar2 == 0x56) {
        esp_zb_zcl_scenes_remove_scene_cb(param_1);
        return;
      }
    }
    else {
      if (uVar2 == 0x58) {
        esp_zb_zcl_scenes_recall_scene_cb(param_1);
        return;
      }
      if (uVar2 == 0x59) {
        esp_zb_zcl_scenes_get_scene_membership_cb(param_1);
        return;
      }
    }
  }
  puVar1[2] = 0xffffffff;
  return;
}

