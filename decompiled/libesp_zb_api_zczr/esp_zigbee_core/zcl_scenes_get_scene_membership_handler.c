/*
 * Last changed at upstream commit 4d04940dfac4dc79b166836b46beea711ac71a6a
 * https://github.com/espressif/esp-zigbee-sdk/commit/4d04940dfac4dc79b166836b46beea711ac71a6a
 * Upstream date: 2023-12-08 17:14:31 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.6(654c5874)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_scenes_get_scene_membership_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_scenes_get_scene_membership_handler(undefined4 param_1)

{
  void *__src;
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  puVar1 = *(undefined2 **)(iVar2 + 0x10);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  __src = *(void **)(iVar2 + 0xc);
  iVar2 = esp_zb_zcl_scenes_group_check(*puVar1,*(undefined1 *)((int)__src + 0xc));
  if (iVar2 == 0) {
    memcpy(&scene_resp_info,__src,0x1b);
    scene_resp_info = *(undefined1 *)puVar1;
    DAT_00016fd1 = *(undefined1 *)((int)puVar1 + 1);
    uVar3 = esp_log_timestamp();
    esp_log_write(3,"ESP_ZIGBEE_CORE",&_L0,uVar3,"ESP_ZIGBEE_CORE");
    zb_buf_get_out_delayed_func(send_get_scene_membership_resp);
  }
  return 0;
}

