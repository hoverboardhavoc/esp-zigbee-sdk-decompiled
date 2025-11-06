/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> data_model_adapter.o -> esp_zb_zcl_get_simple_desc
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
  undefined1 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  
  bVar1 = param_2[2];
  uVar9 = (uint)bVar1;
  bVar2 = param_2[3];
  if (param_1 == 0) {
    uVar8 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_DM_ADAPTER","E (%lu) %s: %s(%d): Invalid cluster array\n",uVar8,
            "ESP_ZIGBEE_DM_ADAPTER","esp_zb_zcl_get_simple_desc",0xcd);
    puVar7 = (undefined1 *)0x0;
  }
  else {
    puVar7 = (undefined1 *)malloc((uVar9 + bVar2 + 4) * 2);
    if (puVar7 == (undefined1 *)0x0) {
      uVar8 = esp_log_timestamp();
      esp_log(1,"ESP_ZIGBEE_DM_ADAPTER","E (%lu) %s: %s(%d): No memory for AF simple desc\n",uVar8,
              "ESP_ZIGBEE_DM_ADAPTER","esp_zb_zcl_get_simple_desc",0xd0);
    }
    else {
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
          esp_log(2,"ESP_ZIGBEE_DM_ADAPTER","W (%lu) %s: Unsupported Cluster Role(0x%x)\n",uVar8,
                  "ESP_ZIGBEE_DM_ADAPTER",puVar5[8]);
        }
      }
    }
  }
  return puVar7;
}

