/*
 * Last changed at upstream commit 8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * https://github.com/espressif/esp-zigbee-sdk/commit/8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * Upstream date: 2023-11-03 16:33:23 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.2(a51c2f72)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_scenes_view_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  if ((iVar2 == 0xff) || (*(short *)(&esp_zb_zcl_scenes_table + iVar2 * 0xc) == -1)) {
    uVar3 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_CORE",&_L0,uVar3,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar1 + 1),
                  *puVar1);
  }
  else {
    memcpy(&scene_resp_info,__src,0x1b);
    _DAT_00016cde = *puVar1;
    DAT_00016ce0 = *(undefined1 *)(puVar1 + 1);
    zb_buf_get_out_delayed_ext_func(send_view_scene_resp,iVar2,0);
  }
  return 0;
}

