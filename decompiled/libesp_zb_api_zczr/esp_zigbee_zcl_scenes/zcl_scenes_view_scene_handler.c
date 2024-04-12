/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_scenes.o -> zcl_scenes_view_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_scenes_view_scene_handler(undefined4 param_1)

{
  undefined2 *puVar1;
  int iVar2;
  void *__src;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  puVar1 = *(undefined2 **)(iVar2 + 0x10);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  __src = *(void **)(iVar2 + 0xc);
  iVar2 = device_scenes_get_free_entry
                    (*(undefined1 *)((int)__src + 0xc),*puVar1,*(undefined1 *)(puVar1 + 1));
  if ((iVar2 != 0xff) && ((&DAT_00011592)[iVar2 * 6] != -1)) {
    memcpy(&scene_resp_info,__src,0x1b);
    DAT_00011576 = *puVar1;
    DAT_00011578 = *(undefined1 *)(puVar1 + 1);
    zb_buf_get_out_delayed_ext_func(send_view_scene_resp,iVar2,0);
  }
  return 0;
}

