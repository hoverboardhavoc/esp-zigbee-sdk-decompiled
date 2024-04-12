/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_flow_meas_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_flow_meas_cluster_add_attr(int param_1,int param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 *__ptr;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined2 uVar6;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar3 = esp_zb_attr_list_get_tail(param_1,0x404,param_2,aiStack_24);
  iVar2 = aiStack_24[0];
  if (aiStack_24[0] == 0) {
    *__ptr = (short)param_2;
    if (param_2 == 0) {
      uVar6 = 0x521;
    }
    else {
      if (2 < (param_2 - 1U & 0xffff)) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC5,uVar4,"ESP_ZIGBEE_ATTRIBUTE");
        free(__ptr);
        return 0x102;
      }
      uVar6 = 0x121;
    }
    __ptr[1] = uVar6;
    puVar5 = (undefined1 *)malloc(2);
    __ptr[4] = (short)((uint)puVar5 >> 0x10);
    uVar1 = *param_3;
    __ptr[3] = (short)puVar5;
    *puVar5 = uVar1;
    puVar5[1] = param_3[1];
    __ptr[2] = 0xffff;
    __ptr[5] = 0x404;
    *(undefined4 *)(__ptr + 6) = 0;
    if (iVar3 == 0) {
      *(undefined2 **)(param_1 + 0xc) = __ptr;
    }
    else {
      *(undefined2 **)(iVar3 + 0xc) = __ptr;
    }
  }
  else {
    free(__ptr);
  }
  return iVar2;
}

