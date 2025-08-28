/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> esp_zb_zcl_scenes_table_set_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_scenes_table_set_size(size_t param_1)

{
  undefined4 uVar1;
  size_t sVar2;
  undefined2 *puVar3;
  
  if (esp_zb_zcl_scenes_table == (void *)0x0) {
    esp_zb_zcl_scenes_table = calloc(param_1,0xc);
    if ((esp_zb_zcl_scenes_table != (void *)0x0) || (uVar1 = 0x101, param_1 == 0)) {
      esp_zb_zcl_scenes_table_capacity = (undefined1)param_1;
      puVar3 = (undefined2 *)((int)esp_zb_zcl_scenes_table + 2);
      s_nvram_app1_data = esp_zb_zcl_scenes_table;
      for (sVar2 = 0; param_1 != sVar2; sVar2 = sVar2 + 1 & 0xff) {
        *puVar3 = 0xffff;
        puVar3 = puVar3 + 6;
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x103;
  }
  return uVar1;
}

