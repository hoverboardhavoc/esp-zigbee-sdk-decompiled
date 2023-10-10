/*
 * Last changed at upstream commit 37b2129eea9960f95d70bf2e6607337834e2750d
 * https://github.com/espressif/esp-zigbee-sdk/commit/37b2129eea9960f95d70bf2e6607337834e2750d
 * Upstream date: 2023-10-10 17:40:24 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.0(8d71c0ae)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_carbon_dioxide_measurement_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_carbon_dioxide_measurement_cluster_add_attr(int param_1,int param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined2 *__ptr;
  int iVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar5 = esp_zb_attr_list_get_tail(param_1,0x40d,param_2,aiStack_24);
  iVar4 = aiStack_24[0];
  if (aiStack_24[0] == 0) {
    *__ptr = (short)param_2;
    if (param_2 == 0) {
      *(undefined1 *)((int)__ptr + 3) = 5;
      *(undefined1 *)(__ptr + 1) = 0x39;
      puVar6 = (undefined1 *)malloc(4);
      __ptr[3] = (short)puVar6;
      __ptr[4] = (short)((uint)puVar6 >> 0x10);
      uVar1 = param_3[1];
      uVar2 = param_3[2];
      uVar3 = param_3[3];
      *puVar6 = *param_3;
      puVar6[1] = uVar1;
      puVar6[2] = uVar2;
      puVar6[3] = uVar3;
    }
    else {
      if (2 < (param_2 - 1U & 0xffff)) {
        uVar7 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_L0,uVar7,"ESP_ZIGBEE_ATTRIBUTE");
        free(__ptr);
        return 0x102;
      }
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x39;
      puVar6 = (undefined1 *)malloc(4);
      __ptr[3] = (short)puVar6;
      __ptr[4] = (short)((uint)puVar6 >> 0x10);
      uVar1 = param_3[1];
      uVar2 = param_3[2];
      uVar3 = param_3[3];
      *puVar6 = *param_3;
      puVar6[1] = uVar1;
      puVar6[2] = uVar2;
      puVar6[3] = uVar3;
    }
    __ptr[2] = 0xffff;
    __ptr[5] = 0x40d;
    *(undefined4 *)(__ptr + 6) = 0;
    aiStack_24[0] = iVar4;
    if (iVar5 == 0) {
      *(undefined2 **)(param_1 + 0xc) = __ptr;
    }
    else {
      *(undefined2 **)(iVar5 + 0xc) = __ptr;
    }
  }
  else {
    free(__ptr);
  }
  return aiStack_24[0];
}

