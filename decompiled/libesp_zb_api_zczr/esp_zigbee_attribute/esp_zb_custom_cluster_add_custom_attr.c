/*
 * Last changed at upstream commit 6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * https://github.com/espressif/esp-zigbee-sdk/commit/6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * Upstream date: 2023-06-09 17:12:37 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.6.2(2626797)
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
  undefined4 *puVar2;
  char *pcVar3;
  size_t sVar4;
  undefined2 *puVar5;
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
    pcVar3 = (char *)malloc(1);
    *pcVar3 = *param_5;
    __ptr[3] = (short)pcVar3;
    __ptr[4] = (short)((uint)pcVar3 >> 0x10);
    goto _L0;
  }
  if (param_3 < 0x29) {
    if (param_3 == 0x21) {
      puVar5 = (undefined2 *)malloc(2);
      *puVar5 = *(undefined2 *)param_5;
      __ptr[3] = (short)puVar5;
      __ptr[4] = (short)((uint)puVar5 >> 0x10);
      goto _L0;
    }
    if (param_3 == 0x23) {
      puVar2 = (undefined4 *)malloc(4);
      *puVar2 = *(undefined4 *)param_5;
      __ptr[3] = (short)puVar2;
      __ptr[4] = (short)((uint)puVar2 >> 0x10);
      goto _L0;
    }
    if (param_3 == 0x20) {
      pcVar3 = (char *)malloc(1);
      *pcVar3 = *param_5;
      __ptr[3] = (short)pcVar3;
      __ptr[4] = (short)((uint)pcVar3 >> 0x10);
      goto _L0;
    }
  }
  else {
    if (param_3 == 0x2b) {
      puVar2 = (undefined4 *)malloc(4);
      *puVar2 = *(undefined4 *)param_5;
      __ptr[3] = (short)puVar2;
      __ptr[4] = (short)((uint)puVar2 >> 0x10);
      goto _L0;
    }
    if (param_3 == 0x42) {
      sVar4 = strlen(param_5);
      pcVar3 = (char *)malloc(sVar4 + 1);
      strcpy(pcVar3,param_5);
      __ptr[3] = (short)pcVar3;
      __ptr[4] = (short)((uint)pcVar3 >> 0x10);
      goto _L0;
    }
    if (param_3 == 0x29) {
      puVar5 = (undefined2 *)malloc(2);
      *puVar5 = *(undefined2 *)param_5;
      __ptr[3] = (short)puVar5;
      __ptr[4] = (short)((uint)puVar5 >> 0x10);
      goto _L0;
    }
  }
  uVar6 = esp_log_timestamp();
  esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC9,uVar6,"ESP_ZIGBEE_ATTRIBUTE");
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

