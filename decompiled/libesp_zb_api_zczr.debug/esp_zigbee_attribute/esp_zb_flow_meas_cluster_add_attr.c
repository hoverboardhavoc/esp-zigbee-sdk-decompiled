/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_flow_meas_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_flow_meas_cluster_add_attr(int param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  undefined2 *__ptr;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar2 = esp_zb_attr_list_get_tail(param_1,0x404,param_2,aiStack_24);
  iVar1 = aiStack_24[0];
  if (aiStack_24[0] == 0) {
    *__ptr = (short)param_2;
    if (param_2 == 0) {
      *(undefined1 *)((int)__ptr + 3) = 5;
      *(undefined1 *)(__ptr + 1) = 0x21;
      puVar3 = (undefined1 *)malloc(2);
      __ptr[3] = (short)puVar3;
      __ptr[4] = (short)((uint)puVar3 >> 0x10);
      *puVar3 = *param_3;
      puVar3[1] = param_3[1];
    }
    else {
      if (2 < (param_2 - 1U & 0xffff)) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_L0,uVar4,0x10000);
        free(__ptr);
        return 0x102;
      }
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x21;
      puVar3 = (undefined1 *)malloc(2);
      __ptr[3] = (short)puVar3;
      __ptr[4] = (short)((uint)puVar3 >> 0x10);
      *puVar3 = *param_3;
      puVar3[1] = param_3[1];
    }
    __ptr[2] = 0xffff;
    __ptr[5] = 0x404;
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
    free(__ptr);
  }
  return aiStack_24[0];
}

