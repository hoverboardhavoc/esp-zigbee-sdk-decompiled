/*
 * Last changed at upstream commit e81a64f4a72a1b96e84882b938e8d601ccb424df
 * https://github.com/espressif/esp-zigbee-sdk/commit/e81a64f4a72a1b96e84882b938e8d601ccb424df
 * Upstream date: 2023-06-30 20:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.7.0(8b8bde0)
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
    device_scene_free_fields((&DAT_000128a4)[iVar3 * 3]);
    *puVar4 = 0;
  }
  return;
}

