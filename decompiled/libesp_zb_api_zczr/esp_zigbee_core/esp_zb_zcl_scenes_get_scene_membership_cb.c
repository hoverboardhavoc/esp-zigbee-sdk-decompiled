/*
 * Last changed at upstream commit e81a64f4a72a1b96e84882b938e8d601ccb424df
 * https://github.com/espressif/esp-zigbee-sdk/commit/e81a64f4a72a1b96e84882b938e8d601ccb424df
 * Upstream date: 2023-06-30 20:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.7.0(8b8bde0)
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
  DAT_00012915 = puVar1[1];
  zb_buf_get_out_delayed_func(send_get_scene_membership_resp);
  return;
}

