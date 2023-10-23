/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_analog_input_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_analog_input_cluster_add_attr(int param_1,uint param_2,char *param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  undefined2 *__ptr;
  int iVar4;
  size_t sVar5;
  char *pcVar6;
  undefined4 uVar7;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar4 = esp_zb_attr_list_get_tail(param_1,0xc,param_2,aiStack_24);
  if (aiStack_24[0] != 0) {
    free(__ptr);
    return aiStack_24[0];
  }
  *__ptr = (short)param_2;
  if (param_2 == 0x67) {
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x30;
    pcVar6 = (char *)malloc(1);
    __ptr[3] = (short)pcVar6;
    __ptr[4] = (short)((uint)pcVar6 >> 0x10);
    *pcVar6 = *param_3;
    goto _L0;
  }
  if (param_2 < 0x68) {
    if (param_2 == 0x51) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x10;
      pcVar6 = (char *)malloc(1);
      *pcVar6 = *param_3;
      __ptr[3] = (short)pcVar6;
      __ptr[4] = (short)((uint)pcVar6 >> 0x10);
      goto _L0;
    }
    if (0x51 < param_2) {
      if (param_2 != 0x55) {
_L0:
        uVar7 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_L0,uVar7,"ESP_ZIGBEE_ATTRIBUTE");
        free(__ptr);
        return 0x102;
      }
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x39;
      pcVar6 = (char *)malloc(4);
      __ptr[3] = (short)pcVar6;
      __ptr[4] = (short)((uint)pcVar6 >> 0x10);
      cVar1 = param_3[1];
      cVar2 = param_3[2];
      cVar3 = param_3[3];
      *pcVar6 = *param_3;
      pcVar6[1] = cVar1;
      pcVar6[2] = cVar2;
      pcVar6[3] = cVar3;
      goto _L0;
    }
    if (param_2 == 0x1c) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x42;
      sVar5 = strlen(param_3);
      pcVar6 = (char *)malloc(sVar5 + 1);
      strcpy(pcVar6,param_3);
      __ptr[3] = (short)pcVar6;
      __ptr[4] = (short)((uint)pcVar6 >> 0x10);
      goto _L0;
    }
    if ((param_2 < 0x1c) || ((param_2 != 0x41 && (param_2 != 0x45)))) goto _L0;
  }
  else {
    if (param_2 == 0x75) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x31;
      pcVar6 = (char *)malloc(2);
      __ptr[3] = (short)pcVar6;
      __ptr[4] = (short)((uint)pcVar6 >> 0x10);
      *pcVar6 = *param_3;
      pcVar6[1] = param_3[1];
      goto _L0;
    }
    if (0x75 < param_2) {
      if (param_2 != 0x100) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x23;
      pcVar6 = (char *)malloc(4);
      __ptr[3] = (short)pcVar6;
      __ptr[4] = (short)((uint)pcVar6 >> 0x10);
      cVar1 = param_3[1];
      cVar2 = param_3[2];
      cVar3 = param_3[3];
      *pcVar6 = *param_3;
      pcVar6[1] = cVar1;
      pcVar6[2] = cVar2;
      pcVar6[3] = cVar3;
      goto _L0;
    }
    if (param_2 != 0x6a) {
      if (param_2 != 0x6f) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 5;
      *(undefined1 *)(__ptr + 1) = 0x18;
      pcVar6 = (char *)malloc(1);
      __ptr[3] = (short)pcVar6;
      __ptr[4] = (short)((uint)pcVar6 >> 0x10);
      *pcVar6 = *param_3;
      goto _L0;
    }
  }
  *(undefined1 *)((int)__ptr + 3) = 1;
  *(undefined1 *)(__ptr + 1) = 0x39;
  pcVar6 = (char *)malloc(4);
  __ptr[3] = (short)pcVar6;
  __ptr[4] = (short)((uint)pcVar6 >> 0x10);
  cVar1 = param_3[1];
  cVar2 = param_3[2];
  cVar3 = param_3[3];
  *pcVar6 = *param_3;
  pcVar6[1] = cVar1;
  pcVar6[2] = cVar2;
  pcVar6[3] = cVar3;
_L0:
  __ptr[2] = 0xffff;
  __ptr[5] = 0xc;
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar4 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar4 + 0xc) = __ptr;
  }
  return 0;
}

