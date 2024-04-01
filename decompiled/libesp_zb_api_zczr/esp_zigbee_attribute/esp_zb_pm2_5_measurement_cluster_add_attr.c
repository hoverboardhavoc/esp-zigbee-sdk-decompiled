/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_pm2_5_measurement_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_pm2_5_measurement_cluster_add_attr(int param_1,int param_2,void *param_3)

{
  int iVar1;
  undefined2 *__ptr;
  int iVar2;
  undefined4 uVar3;
  void *__dest;
  undefined2 uVar4;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar2 = esp_zb_attr_list_get_tail(param_1,0x42a,param_2,aiStack_24);
  iVar1 = aiStack_24[0];
  if (aiStack_24[0] == 0) {
    *__ptr = (short)param_2;
    if (param_2 == 0) {
      uVar4 = 0x539;
    }
    else {
      if (2 < (param_2 - 1U & 0xffff)) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC5,uVar3,"ESP_ZIGBEE_ATTRIBUTE");
        free(__ptr);
        return 0x102;
      }
      uVar4 = 0x139;
    }
    __ptr[1] = uVar4;
    __dest = malloc(4);
    __ptr[4] = (short)((uint)__dest >> 0x10);
    __ptr[3] = (short)__dest;
    memcpy(__dest,param_3,4);
    __ptr[2] = 0xffff;
    __ptr[5] = 0x42a;
    *(undefined4 *)(__ptr + 6) = 0;
    if (iVar2 == 0) {
      *(undefined2 **)(param_1 + 0xc) = __ptr;
    }
    else {
      *(undefined2 **)(iVar2 + 0xc) = __ptr;
    }
  }
  else {
    free(__ptr);
  }
  return iVar1;
}

