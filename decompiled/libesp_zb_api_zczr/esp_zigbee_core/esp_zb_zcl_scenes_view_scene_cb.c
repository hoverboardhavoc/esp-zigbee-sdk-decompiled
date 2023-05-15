/*
 * Last changed at upstream commit e1a2ba67503f907a4a18f5b9e27b306ea1eb6a05
 * https://github.com/espressif/esp-zigbee-sdk/commit/e1a2ba67503f907a4a18f5b9e27b306ea1eb6a05
 * Upstream date: 2023-05-15 14:58:37 +0800
 * Upstream subject: esp-zigbee-lib: Support customized attribute read and command(225be55)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scenes_view_scene_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_view_scene_cb(undefined4 param_1)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  void *__src;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  puVar1 = *(undefined2 **)(iVar2 + 0x10);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  __src = *(void **)(iVar2 + 0xc);
  uVar3 = device_scenes_get_free_entry(*puVar1,*(undefined1 *)(puVar1 + 1));
  memcpy(&scene_resp_info,__src,0x1a);
  scene_resp_info = *(undefined1 *)puVar1;
  DAT_0001222d = *(undefined1 *)((int)puVar1 + 1);
  DAT_0001222e = *(undefined1 *)(puVar1 + 1);
  zb_buf_get_out_delayed_ext_func(send_view_scene_resp,uVar3,0);
  return;
}

