/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> zcl_scenes_view_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_scenes_view_scene_handler(undefined4 param_1)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  void *__src;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  puVar1 = *(undefined2 **)(iVar2 + 0x10);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  __src = *(void **)(iVar2 + 0xc);
  iVar2 = device_scenes_get_free_entry
                    (*(undefined1 *)((int)__src + 0xc),*puVar1,*(undefined1 *)(puVar1 + 1));
  if ((iVar2 == 0xff) || ((&DAT_00012bfa)[iVar2 * 6] == -1)) {
    uVar3 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_ZCL_SCENES",&_L0,uVar3,"ESP_ZIGBEE_ZCL_SCENES",
                  *(undefined1 *)(puVar1 + 1),*puVar1);
  }
  else {
    memcpy(&scene_resp_info,__src,0x1b);
    DAT_00012bde = *puVar1;
    DAT_00012be0 = *(undefined1 *)(puVar1 + 1);
    zb_buf_get_out_delayed_ext_func(send_view_scene_resp,iVar2,0);
  }
  return 0;
}

