/*
 * Last changed at upstream commit d50acd5408f73d4459b46a949332bb6e32f97543
 * https://github.com/espressif/esp-zigbee-sdk/commit/d50acd5408f73d4459b46a949332bb6e32f97543
 * Upstream date: 2023-09-08 17:20:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.4(89250ad3)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_scenes_remove_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_scenes_remove_scene_handler(undefined4 param_1)

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
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC51,uVar3,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar1 + 1),
                    *puVar1);
    }
    else {
      device_scenes_table_record_free();
      uVar3 = esp_log_timestamp();
      esp_log_write(3,"ESP_ZIGBEE_CORE",&_L0,uVar3,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar1 + 1),
                    *puVar1);
      *puVar4 = 0;
    }
  }
  iVar2 = zb_nvram_write_dataset(9);
  if (iVar2 != 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC49,uVar3,"ESP_ZIGBEE_CORE",
                  "zcl_scenes_remove_scene_handler",0x2ce);
    iVar2 = -1;
  }
  return iVar2;
}

