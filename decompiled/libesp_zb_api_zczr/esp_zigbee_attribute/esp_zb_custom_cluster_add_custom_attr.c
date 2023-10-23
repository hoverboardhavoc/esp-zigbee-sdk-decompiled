/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_custom_cluster_add_custom_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_custom_cluster_add_custom_attr
              (int param_1,undefined4 param_2,uint param_3,undefined1 param_4,char *param_5)

{
  undefined2 *__ptr;
  int iVar1;
  char *pcVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  size_t sVar5;
  undefined4 uVar6;
  int aiStack_34 [4];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_34[0] = 0;
  iVar1 = esp_zb_attr_list_get_tail(param_1,0xfc00,param_2,aiStack_34);
  if (aiStack_34[0] != 0) {
    free(__ptr);
    return aiStack_34[0];
  }
  *__ptr = (short)param_2;
  *(char *)(__ptr + 1) = (char)param_3;
  *(undefined1 *)((int)__ptr + 3) = param_4;
  __ptr[2] = 0xffff;
  if (param_3 == 0x28) {
    pcVar2 = (char *)malloc(1);
    *pcVar2 = *param_5;
    __ptr[3] = (short)pcVar2;
    __ptr[4] = (short)((uint)pcVar2 >> 0x10);
    goto _L0;
  }
  if (param_3 < 0x29) {
    if (param_3 == 0x21) {
      puVar3 = (undefined2 *)malloc(2);
      *puVar3 = *(undefined2 *)param_5;
      __ptr[3] = (short)puVar3;
      __ptr[4] = (short)((uint)puVar3 >> 0x10);
      goto _L0;
    }
    if (param_3 == 0x23) {
      puVar4 = (undefined4 *)malloc(4);
      *puVar4 = *(undefined4 *)param_5;
      __ptr[3] = (short)puVar4;
      __ptr[4] = (short)((uint)puVar4 >> 0x10);
      goto _L0;
    }
    if (param_3 == 0x20) {
      pcVar2 = (char *)malloc(1);
      *pcVar2 = *param_5;
      __ptr[3] = (short)pcVar2;
      __ptr[4] = (short)((uint)pcVar2 >> 0x10);
      goto _L0;
    }
  }
  else {
    if (param_3 == 0x2b) {
      puVar4 = (undefined4 *)malloc(4);
      *puVar4 = *(undefined4 *)param_5;
      __ptr[3] = (short)puVar4;
      __ptr[4] = (short)((uint)puVar4 >> 0x10);
      goto _L0;
    }
    if (param_3 == 0x42) {
      sVar5 = strlen(param_5);
      pcVar2 = (char *)malloc(sVar5 + 1);
      strcpy(pcVar2,param_5);
      __ptr[3] = (short)pcVar2;
      __ptr[4] = (short)((uint)pcVar2 >> 0x10);
      goto _L0;
    }
    if (param_3 == 0x29) {
      puVar3 = (undefined2 *)malloc(2);
      *puVar3 = *(undefined2 *)param_5;
      __ptr[3] = (short)puVar3;
      __ptr[4] = (short)((uint)puVar3 >> 0x10);
      goto _L0;
    }
  }
  uVar6 = esp_log_timestamp();
  esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC10,uVar6,"ESP_ZIGBEE_ATTRIBUTE");
_L0:
  __ptr[5] = *(undefined2 *)(iVar1 + 10);
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar1 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar1 + 0xc) = __ptr;
  }
  return 0;
}

