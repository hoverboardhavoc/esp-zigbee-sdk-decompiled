/*
 * Last changed at upstream commit 37b2129eea9960f95d70bf2e6607337834e2750d
 * https://github.com/espressif/esp-zigbee-sdk/commit/37b2129eea9960f95d70bf2e6607337834e2750d
 * Upstream date: 2023-10-10 17:40:24 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.0(8d71c0ae)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_thermostat_ui_config_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_thermostat_ui_config_cluster_add_attr(int param_1,uint param_2,undefined1 *param_3)

{
  int iVar1;
  undefined2 *__ptr;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar2 = esp_zb_attr_list_get_tail(param_1,0x204,param_2,aiStack_24);
  iVar1 = aiStack_24[0];
  if (aiStack_24[0] == 0) {
    *__ptr = (short)param_2;
    if (param_2 < 3) {
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x30;
      puVar3 = (undefined1 *)malloc(1);
      __ptr[3] = (short)puVar3;
      __ptr[4] = (short)((uint)puVar3 >> 0x10);
      *puVar3 = *param_3;
      __ptr[2] = 0xffff;
      __ptr[5] = 0x204;
      *(undefined4 *)(__ptr + 6) = 0;
      aiStack_24[0] = iVar1;
      if (iVar2 == 0) {
        *(undefined2 **)(param_1 + 0xc) = __ptr;
      }
      else {
        *(undefined2 **)(iVar2 + 0xc) = __ptr;
      }
    }
    else {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_L0,uVar4,"ESP_ZIGBEE_ATTRIBUTE");
      free(__ptr);
      aiStack_24[0] = 0x102;
    }
  }
  else {
    free(__ptr);
  }
  return aiStack_24[0];
}

