/*
 * Last changed at upstream commit 6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * https://github.com/espressif/esp-zigbee-sdk/commit/6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * Upstream date: 2023-09-18 10:30:22 +0800
 * Upstream subject: esp-zigbee-sdk: add zigbee trace support and assert support(8c01f3c7)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_scenes_view_scene_handler
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
  iVar2 = device_scenes_get_free_entry(*puVar1,*(undefined1 *)(puVar1 + 1));
  if ((iVar2 == 0xff) || ((&esp_zb_zcl_scenes_table)[iVar2 * 6] == -1)) {
    uVar3 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_CORE",&_L0,uVar3,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar1 + 1),
                  *puVar1);
  }
  else {
    memcpy(&scene_resp_info,__src,0x1b);
    DAT_00015926 = *puVar1;
    DAT_00015928 = *(undefined1 *)(puVar1 + 1);
    zb_buf_get_out_delayed_ext_func(send_view_scene_resp,iVar2,0);
  }
  return 0;
}

