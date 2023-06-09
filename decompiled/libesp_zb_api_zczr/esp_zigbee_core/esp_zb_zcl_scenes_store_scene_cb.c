/*
 * Last changed at upstream commit 6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * https://github.com/espressif/esp-zigbee-sdk/commit/6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * Upstream date: 2023-06-09 17:12:37 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.6.2(2626797)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scenes_store_scene_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_store_scene_cb(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined2 *puVar4;
  int iVar5;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  puVar4 = *(undefined2 **)(iVar2 + 0x10);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  puVar3 = *(undefined1 **)(iVar2 + 0x14);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  iVar5 = *(int *)(iVar2 + 0xc);
  uVar1 = *puVar4;
  iVar2 = device_scenes_get_free_entry(uVar1,*(undefined1 *)(puVar4 + 1));
  if (iVar2 == 0xff) {
    iVar5 = zb_aps_is_endpoint_in_group(uVar1,*(undefined1 *)(iVar5 + 0xc));
    if (iVar5 == 0) {
      *puVar3 = 0x85;
    }
  }
  else {
    if ((&esp_zb_zcl_scenes_table)[iVar2 * 6] == -1) {
      (&esp_zb_zcl_scenes_table)[iVar2 * 6] = uVar1;
      (&DAT_00012540)[iVar2 * 0xc] = *(undefined1 *)(puVar4 + 1);
      *(undefined2 *)(&DAT_0001253e + iVar2 * 0xc) = 0;
    }
    else {
      *puVar3 = 0xe5;
    }
    *puVar3 = 0;
  }
  if (zcl_scenes_store_user_cb != (code *)0x0) {
    (*zcl_scenes_store_user_cb)(*puVar3,(&DAT_00012544)[iVar2 * 3]);
  }
  return;
}

