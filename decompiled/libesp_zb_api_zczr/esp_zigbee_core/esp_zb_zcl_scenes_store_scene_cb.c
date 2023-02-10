/*
 * Last changed at upstream commit baa2c0427a754013932b7b4a3bc21cee014ddd24
 * https://github.com/espressif/esp-zigbee-sdk/commit/baa2c0427a754013932b7b4a3bc21cee014ddd24
 * Upstream date: 2023-02-10 16:01:53 +0800
 * Upstream subject: examples: provide new API for channel set(5818e5d)
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
      (&DAT_00012328)[iVar2 * 0xc] = *(undefined1 *)(puVar4 + 1);
      *(undefined2 *)(&DAT_00012326 + iVar2 * 0xc) = 0;
    }
    else {
      *puVar3 = 0xe5;
    }
    *puVar3 = 0;
  }
  if (zcl_scenes_store_user_cb != (code *)0x0) {
    (*zcl_scenes_store_user_cb)(*puVar3,(&DAT_0001232c)[iVar2 * 3]);
  }
  return;
}

