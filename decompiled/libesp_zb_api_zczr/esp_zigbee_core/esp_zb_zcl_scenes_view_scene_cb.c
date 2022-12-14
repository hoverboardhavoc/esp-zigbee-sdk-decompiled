/*
 * Last changed at upstream commit dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * https://github.com/espressif/esp-zigbee-sdk/commit/dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * Upstream date: 2022-12-14 19:24:05 +0800
 * Upstream subject: examples:Add ota application example(986c075)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scenes_view_scene_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_view_scene_cb(undefined4 param_1)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  int iVar3;
  void *__src;
  
  iVar3 = zb_buf_get_tail_func(0x38);
  puVar1 = *(undefined2 **)(iVar3 + 0x10);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  __src = *(void **)(iVar3 + 0xc);
  uVar2 = device_scenes_get_free_entry(*puVar1,*(undefined1 *)(puVar1 + 1));
  memcpy(scene_resp_info,__src,0x1a);
  scene_resp_info[0x1a] = *(undefined1 *)puVar1;
  scene_resp_info[0x1b] = *(undefined1 *)((int)puVar1 + 1);
  scene_resp_info[0x1c] = *(undefined1 *)(puVar1 + 1);
  zb_buf_get_out_delayed_ext_func(send_view_scene_resp,uVar2,0);
  return;
}

