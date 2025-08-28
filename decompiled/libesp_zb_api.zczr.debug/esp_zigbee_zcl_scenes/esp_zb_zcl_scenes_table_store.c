/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> esp_zb_zcl_scenes_table_store
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_zcl_scenes_table_store
              (undefined4 param_1,undefined4 param_2,undefined2 param_3,undefined2 *param_4)

{
  int iVar1;
  uint uVar2;
  undefined2 *puVar3;
  void *__dest;
  undefined4 uVar4;
  int iVar5;
  undefined2 *puVar6;
  
  uVar2 = device_scenes_get_free_entry();
  if ((uVar2 == 0xff) || (esp_zb_zcl_scenes_table_capacity <= uVar2)) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_SCENES",&_LC36,uVar4,"ESP_ZIGBEE_ZCL_SCENES",
                  "esp_zb_zcl_scenes_table_store",0x21c,param_2);
    iVar1 = -1;
  }
  else {
    iVar1 = uVar2 * 0xc;
    iVar5 = esp_zb_zcl_scenes_table + iVar1;
    *(undefined2 *)(iVar5 + 4) = param_3;
    *(undefined1 *)(iVar5 + 7) = 0;
    if (*(int *)(iVar5 + 8) == 0) {
      zb_zcl_scenes_add_scene_count(param_1,1);
    }
    else {
      device_scene_free_fields();
      *(undefined4 *)(esp_zb_zcl_scenes_table + iVar1 + 8) = 0;
    }
    iVar1 = esp_zb_zcl_scenes_table + iVar1;
    puVar6 = *(undefined2 **)(iVar1 + 8);
    for (; param_4 != (undefined2 *)0x0; param_4 = *(undefined2 **)(param_4 + 4)) {
      puVar3 = (undefined2 *)malloc(0xc);
      *(char *)(iVar1 + 7) = *(char *)(iVar1 + 7) + *(char *)(param_4 + 1) + '\x03';
      *puVar3 = *param_4;
      *(undefined1 *)(puVar3 + 1) = *(undefined1 *)(param_4 + 1);
      *(undefined4 *)(puVar3 + 4) = 0;
      __dest = malloc((uint)*(byte *)(param_4 + 1));
      *(void **)(puVar3 + 2) = __dest;
      memcpy(__dest,*(void **)(param_4 + 2),(uint)*(byte *)(param_4 + 1));
      if (puVar6 == (undefined2 *)0x0) {
        *(undefined2 **)(iVar1 + 8) = puVar3;
      }
      else {
        *(undefined2 **)(puVar6 + 4) = puVar3;
      }
      puVar6 = puVar3;
    }
    iVar1 = zb_nvram_write_dataset(9);
    if (iVar1 != 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ZCL_SCENES",&_LC9,uVar4,"ESP_ZIGBEE_ZCL_SCENES",
                    "esp_zb_zcl_scenes_table_store",0x23c);
      iVar1 = -1;
    }
  }
  return iVar1;
}

