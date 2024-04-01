/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> zcl_scenes_view_scene_handler
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
  if ((iVar2 == 0xff) || ((&DAT_00019ae6)[iVar2 * 6] == -1)) {
    uVar3 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_CORE",&_L0,uVar3,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar1 + 1),
                  *puVar1);
  }
  else {
    memcpy(&scene_resp_info,__src,0x1b);
    DAT_00019aca = *puVar1;
    DAT_00019acc = *(undefined1 *)(puVar1 + 1);
    zb_buf_get_out_delayed_ext_func(send_view_scene_resp,iVar2,0);
  }
  return 0;
}

