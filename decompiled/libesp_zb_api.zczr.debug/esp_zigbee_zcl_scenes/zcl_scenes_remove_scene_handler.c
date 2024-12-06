/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> zcl_scenes_remove_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_scenes_remove_scene_handler(undefined4 param_1)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  
  iVar3 = zb_buf_get_tail_func(0x38);
  puVar2 = *(undefined2 **)(iVar3 + 0x10);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar5 = *(undefined1 **)(iVar3 + 0x14);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  uVar1 = *(undefined1 *)(*(int *)(iVar3 + 0xc) + 0xc);
  iVar3 = esp_zb_zcl_scenes_group_check(uVar1,*puVar2);
  *puVar5 = (char)iVar3;
  if (iVar3 == 0) {
    iVar3 = device_scenes_get_free_entry(uVar1,*puVar2,*(undefined1 *)(puVar2 + 1));
    if ((iVar3 == 0xff) || ((&DAT_00012bfa)[iVar3 * 6] == -1)) {
      *puVar5 = 0x8b;
      uVar4 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_ZCL_SCENES",&_LC8,uVar4,"ESP_ZIGBEE_ZCL_SCENES",
                    *(undefined1 *)(puVar2 + 1),*puVar2);
    }
    else {
      device_scenes_table_record_free();
      uVar4 = esp_log_timestamp();
      esp_log_write(3,"ESP_ZIGBEE_ZCL_SCENES",&_L0,uVar4,"ESP_ZIGBEE_ZCL_SCENES",
                    *(undefined1 *)(puVar2 + 1),*puVar2);
      *puVar5 = 0;
    }
  }
  iVar3 = zb_nvram_write_dataset(9);
  if (iVar3 != 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_SCENES",&_LC6,uVar4,"ESP_ZIGBEE_ZCL_SCENES",
                  "zcl_scenes_remove_scene_handler",0x1d1);
    iVar3 = -1;
  }
  return iVar3;
}

