/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_scenes_remove_all_scenes_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_scenes_remove_all_scenes_handler(undefined4 param_1)

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
    device_scenes_remove_entries_by_group(*puVar1);
    uVar3 = esp_log_timestamp();
    esp_log_write(3,"ESP_ZIGBEE_CORE",&_LC30,uVar3,"ESP_ZIGBEE_CORE",*puVar1);
  }
  iVar2 = zb_nvram_write_dataset(9);
  if (iVar2 != 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC31,uVar3,"ESP_ZIGBEE_CORE",
                  "zcl_scenes_remove_all_scenes_handler",0x2d8);
    iVar2 = -1;
  }
  return iVar2;
}

