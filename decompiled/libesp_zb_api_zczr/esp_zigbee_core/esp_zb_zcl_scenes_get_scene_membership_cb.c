/*
 * Last changed at upstream commit 6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * https://github.com/espressif/esp-zigbee-sdk/commit/6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * Upstream date: 2023-06-09 17:12:37 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.6.2(2626797)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scenes_get_scene_membership_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_get_scene_membership_cb(undefined4 param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  puVar1 = *(undefined1 **)(iVar2 + 0x10);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  memcpy(&scene_resp_info,*(void **)(iVar2 + 0xc),0x1a);
  scene_resp_info = *puVar1;
  DAT_000125b5 = puVar1[1];
  zb_buf_get_out_delayed_func(send_get_scene_membership_resp);
  return;
}

