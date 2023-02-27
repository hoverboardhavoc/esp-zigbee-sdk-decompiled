/*
 * Last changed at upstream commit b278a1511ed728943e19c371f88a01e9d130f19f
 * https://github.com/espressif/esp-zigbee-sdk/commit/b278a1511ed728943e19c371f88a01e9d130f19f
 * Upstream date: 2023-02-27 14:43:05 +0800
 * Upstream subject: zcl: add ZCL API for color and report attribute(af3fa1e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scenes_recall_scene_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_recall_scene_cb(undefined4 param_1)

{
  undefined2 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  iVar3 = zb_buf_get_tail_func(0x38);
  puVar1 = *(undefined2 **)(iVar3 + 0x10);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar2 = *(undefined1 **)(iVar3 + 0x14);
  iVar3 = device_scenes_get_free_entry(*puVar1,*(undefined1 *)(puVar1 + 1));
  if ((iVar3 == 0xff) || ((&esp_zb_zcl_scenes_table)[iVar3 * 6] == -1)) {
    *puVar2 = 0x8b;
  }
  else {
    *puVar2 = 0;
  }
  if (zcl_scenes_recall_user_cb != (code *)0x0) {
    (*zcl_scenes_recall_user_cb)(*puVar2,(&DAT_00012324)[iVar3 * 3]);
  }
  return;
}

