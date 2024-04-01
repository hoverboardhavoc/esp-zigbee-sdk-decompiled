/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_meter_identification_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_meter_identification_cluster_add_attr(int param_1,uint param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  undefined2 *__ptr;
  int iVar3;
  undefined4 uVar4;
  void *__dest;
  char *pcVar5;
  size_t sVar6;
  undefined2 uVar7;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar3 = esp_zb_attr_list_get_tail(param_1,0xb01,param_2,aiStack_24);
  iVar2 = aiStack_24[0];
  if (aiStack_24[0] != 0) {
    free(__ptr);
    return iVar2;
  }
  *__ptr = (short)param_2;
  if (param_2 < 9) {
    if (5 < param_2) goto _L0;
    if (param_2 == 4) {
_L0:
      __ptr[1] = 0x121;
      pcVar5 = (char *)malloc(2);
      __ptr[4] = (short)((uint)pcVar5 >> 0x10);
      cVar1 = *param_3;
      __ptr[3] = (short)pcVar5;
      *pcVar5 = cVar1;
      pcVar5[1] = param_3[1];
      goto _L0;
    }
    if (param_2 == 5) {
      uVar7 = 0x342;
    }
    else {
      uVar7 = 0x142;
      if (param_2 != 0) {
        if (param_2 != 1) goto _L0;
        goto _L0;
      }
    }
  }
  else {
    if (0xc < param_2) {
      if (1 < (param_2 - 0xd & 0xffff)) goto _L0;
      __ptr[1] = 0x12a;
      __dest = malloc(3);
      __ptr[3] = (short)__dest;
      __ptr[4] = (short)((uint)__dest >> 0x10);
      memcpy(__dest,param_3,3);
      goto _L0;
    }
    if ((param_2 < 0xb) && (param_2 != 10)) {
_L0:
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC5,uVar4,"ESP_ZIGBEE_ATTRIBUTE");
      free(__ptr);
      return 0x102;
    }
_L0:
    uVar7 = 0x141;
  }
  __ptr[1] = uVar7;
  sVar6 = strlen(param_3);
  pcVar5 = (char *)malloc(sVar6 + 1);
  __ptr[3] = (short)pcVar5;
  __ptr[4] = (short)((uint)pcVar5 >> 0x10);
  strcpy(pcVar5,param_3);
_L0:
  __ptr[2] = 0xffff;
  __ptr[5] = 0xb01;
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar3 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar3 + 0xc) = __ptr;
  }
  return 0;
}

