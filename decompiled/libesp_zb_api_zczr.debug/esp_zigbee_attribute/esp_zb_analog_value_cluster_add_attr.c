/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_analog_value_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_analog_value_cluster_add_attr(int param_1,uint param_2,char *param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  undefined2 *__ptr;
  int iVar4;
  char *pcVar5;
  size_t sVar6;
  undefined4 uVar7;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar4 = esp_zb_attr_list_get_tail(param_1,0xe,param_2,aiStack_24);
  if (aiStack_24[0] != 0) {
    free(__ptr);
    return aiStack_24[0];
  }
  *__ptr = (short)param_2;
  if (param_2 == 0x68) {
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x39;
    pcVar5 = (char *)malloc(4);
    __ptr[3] = (short)pcVar5;
    __ptr[4] = (short)((uint)pcVar5 >> 0x10);
    cVar1 = param_3[1];
    cVar2 = param_3[2];
    cVar3 = param_3[3];
    *pcVar5 = *param_3;
    pcVar5[1] = cVar1;
    pcVar5[2] = cVar2;
    pcVar5[3] = cVar3;
  }
  else if (param_2 < 0x69) {
    if (param_2 == 0x55) {
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x39;
      pcVar5 = (char *)malloc(4);
      __ptr[3] = (short)pcVar5;
      __ptr[4] = (short)((uint)pcVar5 >> 0x10);
      cVar1 = param_3[1];
      cVar2 = param_3[2];
      cVar3 = param_3[3];
      *pcVar5 = *param_3;
      pcVar5[1] = cVar1;
      pcVar5[2] = cVar2;
      pcVar5[3] = cVar3;
    }
    else if (param_2 < 0x56) {
      if (param_2 == 0x1c) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x42;
        sVar6 = strlen(param_3);
        pcVar5 = (char *)malloc(sVar6 + 1);
        strcpy(pcVar5,param_3);
        __ptr[3] = (short)pcVar5;
        __ptr[4] = (short)((uint)pcVar5 >> 0x10);
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
    else {
      if (param_2 != 0x67) {
_L0:
        uVar7 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_L0,uVar7,0x10000);
        free(__ptr);
        return 0x102;
      }
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x30;
      pcVar5 = (char *)malloc(1);
      __ptr[3] = (short)pcVar5;
      __ptr[4] = (short)((uint)pcVar5 >> 0x10);
      *pcVar5 = *param_3;
    }
  }
  else if (param_2 == 0x75) {
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x31;
    pcVar5 = (char *)malloc(2);
    __ptr[3] = (short)pcVar5;
    __ptr[4] = (short)((uint)pcVar5 >> 0x10);
    *pcVar5 = *param_3;
    pcVar5[1] = param_3[1];
  }
  else if (param_2 == 0x100) {
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x23;
    pcVar5 = (char *)malloc(4);
    __ptr[3] = (short)pcVar5;
    __ptr[4] = (short)((uint)pcVar5 >> 0x10);
    cVar1 = param_3[1];
    cVar2 = param_3[2];
    cVar3 = param_3[3];
    *pcVar5 = *param_3;
    pcVar5[1] = cVar1;
    pcVar5[2] = cVar2;
    pcVar5[3] = cVar3;
  }
  else {
    if (param_2 != 0x6f) goto _L0;
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x18;
    pcVar5 = (char *)malloc(1);
    __ptr[3] = (short)pcVar5;
    __ptr[4] = (short)((uint)pcVar5 >> 0x10);
    *pcVar5 = *param_3;
  }
  __ptr[2] = 0xffff;
  __ptr[5] = 0xe;
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar4 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar4 + 0xc) = __ptr;
  }
  return 0;
}

