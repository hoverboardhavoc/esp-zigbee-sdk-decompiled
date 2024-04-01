/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_diagnostics_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_diagnostics_cluster_add_attr(int param_1,uint param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 *__ptr;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  void *__dest;
  undefined2 uVar6;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar3 = esp_zb_attr_list_get_tail(param_1,0xb05,param_2,aiStack_24);
  iVar2 = aiStack_24[0];
  if (aiStack_24[0] != 0) {
    free(__ptr);
    return iVar2;
  }
  *__ptr = (short)param_2;
  if (param_2 < 0x11c) {
    if (param_2 < 0x104) {
      if (param_2 < 2) {
        __ptr[1] = 0x121;
        puVar5 = (undefined1 *)malloc(2);
        __ptr[4] = (short)((uint)puVar5 >> 0x10);
        uVar1 = *param_3;
        __ptr[3] = (short)puVar5;
        *puVar5 = uVar1;
        puVar5[1] = param_3[1];
      }
      else {
        if (3 < (param_2 - 0x100 & 0xffff)) goto _L0;
        __ptr[1] = 0x123;
        __dest = malloc(4);
        __ptr[3] = (short)__dest;
        __ptr[4] = (short)((uint)__dest >> 0x10);
        memcpy(__dest,param_3,4);
      }
    }
    else {
      __ptr[1] = 0x121;
      puVar5 = (undefined1 *)malloc(2);
      __ptr[4] = (short)((uint)puVar5 >> 0x10);
      uVar1 = *param_3;
      __ptr[3] = (short)puVar5;
      *puVar5 = uVar1;
      puVar5[1] = param_3[1];
    }
  }
  else {
    if (param_2 == 0x11c) {
      uVar6 = 0x120;
    }
    else {
      if (param_2 != 0x11d) {
_L0:
        uVar4 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC5,uVar4,"ESP_ZIGBEE_ATTRIBUTE");
        free(__ptr);
        return 0x102;
      }
      uVar6 = 0x128;
    }
    __ptr[1] = uVar6;
    puVar5 = (undefined1 *)malloc(1);
    __ptr[4] = (short)((uint)puVar5 >> 0x10);
    uVar1 = *param_3;
    __ptr[3] = (short)puVar5;
    *puVar5 = uVar1;
  }
  __ptr[2] = 0xffff;
  __ptr[5] = 0xb05;
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar3 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar3 + 0xc) = __ptr;
  }
  return 0;
}

