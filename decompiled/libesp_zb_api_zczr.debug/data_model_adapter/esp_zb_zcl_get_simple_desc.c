/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> data_model_adapter.o -> esp_zb_zcl_get_simple_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * esp_zb_zcl_get_simple_desc(int param_1,byte *param_2,undefined1 *param_3)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  byte bVar4;
  undefined1 *puVar5;
  uint uVar6;
  void *__ptr;
  undefined1 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  
  bVar1 = param_2[2];
  uVar9 = (uint)bVar1;
  bVar2 = param_2[3];
  if (param_1 == 0) {
    uVar8 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_DM_ADAPTER",&_L0,uVar8,"ESP_ZIGBEE_DM_ADAPTER",
                  "esp_zb_zcl_get_simple_desc",0xcb);
    puVar7 = (undefined1 *)0x0;
  }
  else {
    __ptr = malloc(0xc);
    puVar7 = (undefined1 *)realloc(__ptr,(uVar9 + bVar2 + 4) * 2);
    *puVar7 = *param_3;
    uVar3 = param_3[2];
    puVar7[1] = param_3[1];
    puVar7[2] = uVar3;
    uVar3 = param_3[4];
    puVar7[3] = param_3[3];
    puVar7[4] = uVar3;
    bVar4 = param_3[5];
    puVar7[5] = puVar7[5] & 0xf0 | bVar4 & 0xf;
    puVar7[5] = bVar4 & 0xf;
    puVar7[6] = bVar1;
    puVar7[7] = bVar2;
    uVar10 = 0;
    for (uVar6 = 0; uVar6 < *param_2; uVar6 = uVar6 + 1 & 0xff) {
      puVar5 = (undefined1 *)(uVar6 * 0xf + param_1);
      if (puVar5[8] == '\x01') {
        uVar3 = puVar5[1];
        puVar7[uVar10 * 2 + 8] = *puVar5;
        puVar7[uVar10 * 2 + 9] = uVar3;
        uVar10 = uVar10 + 1 & 0xff;
      }
      else if (puVar5[8] == '\x02') {
        uVar3 = puVar5[1];
        puVar7[uVar9 * 2 + 8] = *puVar5;
        puVar7[uVar9 * 2 + 9] = uVar3;
        uVar9 = uVar9 + 1 & 0xff;
      }
      else {
        uVar8 = esp_log_timestamp();
        esp_log_write(2,"ESP_ZIGBEE_DM_ADAPTER",&_LC10,uVar8,"ESP_ZIGBEE_DM_ADAPTER",puVar5[8]);
      }
    }
  }
  return puVar7;
}

