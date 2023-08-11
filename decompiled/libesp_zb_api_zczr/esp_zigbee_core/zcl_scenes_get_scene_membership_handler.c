/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_scenes_get_scene_membership_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_scenes_get_scene_membership_handler(undefined4 param_1)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 uVar4;
  void *__src;
  
  iVar3 = zb_buf_get_tail_func(0x38);
  puVar2 = *(undefined2 **)(iVar3 + 0x10);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  __src = *(void **)(iVar3 + 0xc);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar1 = *(undefined1 **)(iVar3 + 0x14);
  iVar3 = esp_zb_zcl_scenes_group_check(*puVar2,*(undefined1 *)((int)__src + 0xc));
  *puVar1 = (char)iVar3;
  if (iVar3 == 0) {
    memcpy(&scene_resp_info,__src,0x1b);
    scene_resp_info = *(undefined1 *)puVar2;
    DAT_00014585 = *(undefined1 *)((int)puVar2 + 1);
    uVar4 = esp_log_timestamp();
    esp_log_write(3,"ESP_ZIGBEE_CORE",&_L0,uVar4,"ESP_ZIGBEE_CORE");
    zb_buf_get_out_delayed_func(send_get_scene_membership_resp);
  }
  return 0;
}

