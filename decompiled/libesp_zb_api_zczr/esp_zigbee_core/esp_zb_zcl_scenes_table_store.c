/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scenes_table_store
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
    (&DAT_00017f78)[uVar1 * 6] = param_2;
    (&DAT_00017f7b)[uVar1 * 0xc] = 0;
    if ((&DAT_00017f7c)[uVar1 * 3] != 0) {
      device_scene_free_fields();
      (&DAT_00017f7c)[uVar1 * 3] = 0;
    }
    puVar5 = (undefined2 *)(&DAT_00017f7c)[uVar1 * 3];
    for (; param_3 != (undefined2 *)0x0; param_3 = *(undefined2 **)(param_3 + 4)) {
      puVar2 = (undefined2 *)malloc(0xc);
      (&DAT_00017f7b)[uVar1 * 0xc] = (&DAT_00017f7b)[uVar1 * 0xc] + *(char *)(param_3 + 1) + '\x03';
      *puVar2 = *param_3;
      *(undefined1 *)(puVar2 + 1) = *(undefined1 *)(param_3 + 1);
      *(undefined4 *)(puVar2 + 4) = 0;
      __dest = malloc((uint)*(byte *)(param_3 + 1));
      *(void **)(puVar2 + 2) = __dest;
      memcpy(__dest,*(void **)(param_3 + 2),(uint)*(byte *)(param_3 + 1));
      if (puVar5 == (undefined2 *)0x0) {
        (&DAT_00017f7c)[uVar1 * 3] = puVar2;
      }
      else {
        *(undefined2 **)(puVar5 + 4) = puVar2;
      }
      puVar5 = puVar2;
    }
    iVar3 = zb_nvram_write_dataset(9);
    if (iVar3 != 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC37,uVar4,"ESP_ZIGBEE_CORE",
                    "esp_zb_zcl_scenes_table_store",0x39d);
      iVar3 = -1;
    }
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar4,"ESP_ZIGBEE_CORE","esp_zb_zcl_scenes_table_store",
                  0x380,param_1);
    iVar3 = -1;
  }
  return iVar3;
}

