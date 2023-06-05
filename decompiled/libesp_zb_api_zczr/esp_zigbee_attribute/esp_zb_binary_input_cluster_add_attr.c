/*
 * Last changed at upstream commit 503c5e49627f84174ce142bf784c3f01532fb5c9
 * https://github.com/espressif/esp-zigbee-sdk/commit/503c5e49627f84174ce142bf784c3f01532fb5c9
 * Upstream date: 2023-06-05 10:37:46 +0800
 * Upstream subject: esp-zigbee-sdk: optimize the zigbee cluster implementation(0f0acd4)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_binary_input_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_binary_input_cluster_add_attr(int param_1,uint param_2,char *param_3)

{
  ushort *puVar1;
  ushort *puVar2;
  undefined2 *__ptr;
  undefined4 *puVar3;
  size_t sVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  __ptr = (undefined2 *)malloc(0x10);
  if (param_1 == 0) {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC1,uVar6,"ESP_ZIGBEE_ATTRIBUTE");
    return 0x102;
  }
  puVar1 = *(ushort **)(param_1 + 0xc);
  if ((*(ushort **)(param_1 + 0xc))[5] != 0xf) {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC7,uVar6,"ESP_ZIGBEE_ATTRIBUTE");
    return 0x102;
  }
  do {
    puVar2 = puVar1;
    if (puVar2 == (ushort *)0x0) break;
    if (*puVar2 == param_2) {
      uVar6 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC4,uVar6,"ESP_ZIGBEE_ATTRIBUTE",param_2);
      return 0x102;
    }
    puVar1 = *(ushort **)(puVar2 + 6);
  } while (*(ushort **)(puVar2 + 6) != (ushort *)0x0);
  *__ptr = (short)param_2;
  if (param_2 == 0x54) {
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x18;
    pcVar5 = (char *)malloc(1);
    *pcVar5 = *param_3;
    __ptr[3] = (short)pcVar5;
    __ptr[4] = (short)((uint)pcVar5 >> 0x10);
  }
  else if (param_2 < 0x55) {
    if (param_2 == 0x2e) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x42;
      sVar4 = strlen(param_3);
      pcVar5 = (char *)malloc(sVar4 + 1);
      strcpy(pcVar5,param_3);
      __ptr[3] = (short)pcVar5;
      __ptr[4] = (short)((uint)pcVar5 >> 0x10);
    }
    else if (param_2 < 0x2f) {
      if (param_2 == 4) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x42;
        sVar4 = strlen(param_3);
        pcVar5 = (char *)malloc(sVar4 + 1);
        strcpy(pcVar5,param_3);
        __ptr[3] = (short)pcVar5;
        __ptr[4] = (short)((uint)pcVar5 >> 0x10);
      }
      else {
        if (param_2 != 0x1c) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x42;
        sVar4 = strlen(param_3);
        pcVar5 = (char *)malloc(sVar4 + 1);
        strcpy(pcVar5,param_3);
        __ptr[3] = (short)pcVar5;
        __ptr[4] = (short)((uint)pcVar5 >> 0x10);
      }
    }
    else {
      if (param_2 != 0x51) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x10;
      pcVar5 = (char *)malloc(1);
      *pcVar5 = *param_3;
      __ptr[3] = (short)pcVar5;
      __ptr[4] = (short)((uint)pcVar5 >> 0x10);
    }
  }
  else if (param_2 == 0x6f) {
    *(undefined1 *)((int)__ptr + 3) = 5;
    *(undefined1 *)(__ptr + 1) = 0x18;
    pcVar5 = (char *)malloc(1);
    *pcVar5 = *param_3;
    __ptr[3] = (short)pcVar5;
    __ptr[4] = (short)((uint)pcVar5 >> 0x10);
  }
  else if (param_2 < 0x70) {
    if (param_2 == 0x55) {
      *(undefined1 *)((int)__ptr + 3) = 5;
      *(undefined1 *)(__ptr + 1) = 0x10;
      pcVar5 = (char *)malloc(1);
      *pcVar5 = *param_3;
      __ptr[3] = (short)pcVar5;
      __ptr[4] = (short)((uint)pcVar5 >> 0x10);
    }
    else {
      if (param_2 != 0x67) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x18;
      pcVar5 = (char *)malloc(1);
      *pcVar5 = *param_3;
      __ptr[3] = (short)pcVar5;
      __ptr[4] = (short)((uint)pcVar5 >> 0x10);
    }
  }
  else {
    if (param_2 != 0x100) {
_L0:
      uVar6 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_L0,uVar6,"ESP_ZIGBEE_ATTRIBUTE");
      free(__ptr);
      return 0x102;
    }
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x23;
    puVar3 = (undefined4 *)malloc(4);
    *puVar3 = *(undefined4 *)param_3;
    __ptr[3] = (short)puVar3;
    __ptr[4] = (short)((uint)puVar3 >> 0x10);
  }
  __ptr[2] = 0xffff;
  __ptr[5] = 0xf;
  *(undefined4 *)(__ptr + 6) = 0;
  if (puVar2 == (ushort *)0x0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(puVar2 + 6) = __ptr;
  }
  return 0;
}

