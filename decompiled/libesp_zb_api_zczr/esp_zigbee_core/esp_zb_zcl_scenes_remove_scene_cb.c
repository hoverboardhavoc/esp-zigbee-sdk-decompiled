/*
 * Last changed at upstream commit 6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * https://github.com/espressif/esp-zigbee-sdk/commit/6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * Upstream date: 2023-06-09 17:12:37 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.6.2(2626797)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scenes_remove_scene_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_remove_scene_cb(undefined4 param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  
  iVar3 = zb_buf_get_tail_func(0x38);
  puVar2 = *(undefined2 **)(iVar3 + 0x10);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar4 = *(undefined1 **)(iVar3 + 0x14);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  iVar5 = *(int *)(iVar3 + 0xc);
  uVar1 = *puVar2;
  iVar3 = device_scenes_get_free_entry(uVar1,*(undefined1 *)(puVar2 + 1));
  if ((iVar3 == 0xff) || ((&esp_zb_zcl_scenes_table)[iVar3 * 6] == -1)) {
    iVar3 = zb_aps_is_endpoint_in_group(uVar1,*(undefined1 *)(iVar5 + 0xc));
    if (iVar3 == 0) {
      *puVar4 = 0x85;
    }
  }
  else {
    (&esp_zb_zcl_scenes_table)[iVar3 * 6] = 0xffff;
    device_scene_free_fields((&DAT_00012544)[iVar3 * 3]);
    *puVar4 = 0;
  }
  return;
}

