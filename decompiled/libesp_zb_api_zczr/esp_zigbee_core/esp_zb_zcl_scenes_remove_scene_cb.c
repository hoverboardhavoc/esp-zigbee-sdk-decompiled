/*
 * Last changed at upstream commit 1f6b611e278a00f885edde9cb38294c3c08373a5
 * https://github.com/espressif/esp-zigbee-sdk/commit/1f6b611e278a00f885edde9cb38294c3c08373a5
 * Upstream date: 2023-08-01 20:17:41 +0800
 * Upstream subject: esp-zigbee-sdk: fix zigbee zcl scenes extension field implementation
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scenes_remove_scene_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_remove_scene_cb(undefined4 param_1)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  puVar1 = *(undefined2 **)(iVar2 + 0x10);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  puVar4 = *(undefined1 **)(iVar2 + 0x14);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  iVar2 = esp_zb_zcl_scenes_group_check(*puVar1,*(undefined1 *)(*(int *)(iVar2 + 0xc) + 0xc));
  *puVar4 = (char)iVar2;
  if (iVar2 == 0) {
    iVar2 = device_scenes_get_free_entry(*puVar1,*(undefined1 *)(puVar1 + 1));
    if ((iVar2 == 0xff) || ((&esp_zb_zcl_scenes_table)[iVar2 * 6] == -1)) {
      *puVar4 = 0x8b;
      uVar3 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC14,uVar3,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar1 + 1),
                    *puVar1);
    }
    else {
      (&esp_zb_zcl_scenes_table)[iVar2 * 6] = 0xffff;
      device_scene_free_fields((&DAT_000137ac)[iVar2 * 3]);
      (&DAT_000137ac)[iVar2 * 3] = 0;
      uVar3 = esp_log_timestamp();
      esp_log_write(3,"ESP_ZIGBEE_CORE",&_LC13,uVar3,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar1 + 1),
                    *puVar1);
      *puVar4 = 0;
    }
  }
  return;
}

