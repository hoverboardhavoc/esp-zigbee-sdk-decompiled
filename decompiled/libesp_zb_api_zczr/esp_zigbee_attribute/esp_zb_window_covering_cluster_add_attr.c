/*
 * Last changed at upstream commit 6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * https://github.com/espressif/esp-zigbee-sdk/commit/6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * Upstream date: 2023-06-09 17:12:37 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.6.2(2626797)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_window_covering_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_window_covering_cluster_add_attr(int param_1,uint param_2,char *param_3)

{
  undefined2 *__ptr;
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  void *__dest;
  undefined4 uVar4;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar1 = esp_zb_attr_list_get_tail(param_1,0x102,param_2,aiStack_24);
  if (aiStack_24[0] != 0) {
    free(__ptr);
    return aiStack_24[0];
  }
  *__ptr = (short)param_2;
  if (0x13 < param_2) {
    if (param_2 == 0x17) {
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x18;
      pcVar2 = (char *)malloc(1);
      __ptr[3] = (short)pcVar2;
      __ptr[4] = (short)((uint)pcVar2 >> 0x10);
      *pcVar2 = *param_3;
    }
    else if (param_2 < 0x18) {
      if (2 < (param_2 - 0x14 & 0xffff)) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x21;
      pcVar2 = (char *)malloc(2);
      __ptr[3] = (short)pcVar2;
      __ptr[4] = (short)((uint)pcVar2 >> 0x10);
      *pcVar2 = *param_3;
      pcVar2[1] = param_3[1];
    }
    else {
      if (1 < (param_2 - 0x18 & 0xffff)) {
_L0:
        uVar4 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_L0,uVar4,"ESP_ZIGBEE_ATTRIBUTE");
        free(__ptr);
        return 0x102;
      }
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x41;
      sVar3 = strlen(param_3);
      __dest = malloc(sVar3 + 1);
      __ptr[3] = (short)__dest;
      __ptr[4] = (short)((uint)__dest >> 0x10);
      sVar3 = strlen(param_3);
      memcpy(__dest,param_3,sVar3 + 1);
    }
    goto _L0;
  }
  if (param_2 < 0x10) {
    if (param_2 == 7) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x18;
      pcVar2 = (char *)malloc(1);
      __ptr[3] = (short)pcVar2;
      __ptr[4] = (short)((uint)pcVar2 >> 0x10);
      *pcVar2 = *param_3;
      goto _L0;
    }
    if (7 < param_2) {
      if (1 < (param_2 - 8 & 0xffff)) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 0x15;
      *(undefined1 *)(__ptr + 1) = 0x20;
      pcVar2 = (char *)malloc(2);
      __ptr[3] = (short)pcVar2;
      __ptr[4] = (short)((uint)pcVar2 >> 0x10);
      *pcVar2 = *param_3;
      pcVar2[1] = param_3[1];
      goto _L0;
    }
    if (param_2 == 0) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x30;
      goto _L0;
    }
    if (5 < (param_2 - 1 & 0xffff)) goto _L0;
  }
  *(undefined1 *)((int)__ptr + 3) = 1;
  *(undefined1 *)(__ptr + 1) = 0x21;
  pcVar2 = (char *)malloc(2);
  __ptr[3] = (short)pcVar2;
  __ptr[4] = (short)((uint)pcVar2 >> 0x10);
  *pcVar2 = *param_3;
  pcVar2[1] = param_3[1];
_L0:
  __ptr[2] = 0xffff;
  __ptr[5] = 0x102;
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar1 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar1 + 0xc) = __ptr;
  }
  return 0;
}

