/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> zcl_scenes_get_scene_membership_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_scenes_get_scene_membership_handler(undefined4 param_1)

{
  undefined2 *puVar1;
  void *__src;
  int iVar2;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  puVar1 = *(undefined2 **)(iVar2 + 0x10);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  __src = *(void **)(iVar2 + 0xc);
  iVar2 = esp_zb_zcl_scenes_group_check(*(undefined1 *)((int)__src + 0xc),*puVar1);
  if (iVar2 == 0) {
    memcpy(&scene_resp_info,__src,0x1b);
    scene_resp_info = *(undefined1 *)puVar1;
    DAT_00011569 = *(undefined1 *)((int)puVar1 + 1);
    zb_buf_get_out_delayed_func(send_get_scene_membership_resp);
  }
  return 0;
}

