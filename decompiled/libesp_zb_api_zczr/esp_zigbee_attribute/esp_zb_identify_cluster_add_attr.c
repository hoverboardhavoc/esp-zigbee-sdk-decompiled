/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_identify_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_identify_cluster_add_attr(int param_1,int param_2,undefined2 *param_3)

{
  undefined2 uVar1;
  undefined2 *__ptr;
  int iVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar2 = esp_zb_attr_list_get_tail(param_1,3,param_2,aiStack_24);
  iVar5 = aiStack_24[0];
  if (aiStack_24[0] == 0) {
    *__ptr = (short)param_2;
    if (param_2 == 0) {
      puVar3 = (undefined2 *)malloc(2);
      uVar1 = *param_3;
      __ptr[4] = (short)((uint)puVar3 >> 0x10);
      __ptr[1] = 0x321;
      __ptr[2] = 0xffff;
      *puVar3 = uVar1;
      __ptr[3] = (short)puVar3;
      __ptr[5] = 3;
      *(undefined4 *)(__ptr + 6) = 0;
      if (iVar2 == 0) {
        *(undefined2 **)(param_1 + 0xc) = __ptr;
      }
      else {
        *(undefined2 **)(iVar2 + 0xc) = __ptr;
      }
    }
    else {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC5,uVar4,"ESP_ZIGBEE_ATTRIBUTE");
      free(__ptr);
      iVar5 = 0x102;
    }
  }
  else {
    free(__ptr);
  }
  return iVar5;
}

