/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> esp_zb_zcl_scenes_table_store
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_zcl_scenes_table_store(undefined4 param_1,undefined2 param_2,undefined2 *param_3)

{
  uint uVar1;
  undefined2 *puVar2;
  void *__dest;
  int iVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  
  uVar1 = device_scenes_get_free_entry();
  if (uVar1 < 0x10) {
    (&DAT_00019ae8)[uVar1 * 6] = param_2;
    (&DAT_00019aeb)[uVar1 * 0xc] = 0;
    if ((&DAT_00019aec)[uVar1 * 3] != 0) {
      device_scene_free_fields();
      (&DAT_00019aec)[uVar1 * 3] = 0;
    }
    puVar5 = (undefined2 *)(&DAT_00019aec)[uVar1 * 3];
    for (; param_3 != (undefined2 *)0x0; param_3 = *(undefined2 **)(param_3 + 4)) {
      puVar2 = (undefined2 *)malloc(0xc);
      (&DAT_00019aeb)[uVar1 * 0xc] = (&DAT_00019aeb)[uVar1 * 0xc] + *(char *)(param_3 + 1) + '\x03';
      *puVar2 = *param_3;
      *(undefined1 *)(puVar2 + 1) = *(undefined1 *)(param_3 + 1);
      *(undefined4 *)(puVar2 + 4) = 0;
      __dest = malloc((uint)*(byte *)(param_3 + 1));
      *(void **)(puVar2 + 2) = __dest;
      memcpy(__dest,*(void **)(param_3 + 2),(uint)*(byte *)(param_3 + 1));
      if (puVar5 == (undefined2 *)0x0) {
        (&DAT_00019aec)[uVar1 * 3] = puVar2;
      }
      else {
        *(undefined2 **)(puVar5 + 4) = puVar2;
      }
      puVar5 = puVar2;
    }
    iVar3 = zb_nvram_write_dataset(9);
    if (iVar3 != 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC46,uVar4,"ESP_ZIGBEE_CORE",
                    "esp_zb_zcl_scenes_table_store",0x3a8);
      iVar3 = -1;
    }
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC81,uVar4,"ESP_ZIGBEE_CORE","esp_zb_zcl_scenes_table_store"
                  ,0x38b,param_1);
    iVar3 = -1;
  }
  return iVar3;
}

