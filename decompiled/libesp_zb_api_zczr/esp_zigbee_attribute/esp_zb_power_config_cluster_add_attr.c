/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_power_config_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_power_config_cluster_add_attr(int param_1,uint param_2,char *param_3)

{
  int iVar1;
  undefined2 *__ptr;
  int iVar2;
  undefined4 uVar3;
  char *__dest;
  size_t sVar4;
  undefined2 uVar5;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar2 = esp_zb_attr_list_get_tail(param_1,1,param_2,aiStack_24);
  iVar1 = aiStack_24[0];
  if (aiStack_24[0] != 0) {
    free(__ptr);
    return iVar1;
  }
  *__ptr = (short)param_2;
  if (param_2 == 0x33) {
_L0:
    uVar5 = 800;
  }
  else if (param_2 < 0x34) {
    if (param_2 == 0x13) {
_L0:
      uVar5 = 0x321;
_L0:
      __ptr[1] = uVar5;
      __dest = (char *)malloc(2);
      *(undefined2 *)__dest = *(undefined2 *)param_3;
      goto _L0;
    }
    if (param_2 < 0x14) {
      if (param_2 != 0x10) {
        if (0x10 < param_2) goto _L0;
        if (param_2 != 0) {
          if (param_2 != 1) {
_L0:
            uVar3 = esp_log_timestamp();
            esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC5,uVar3,"ESP_ZIGBEE_ATTRIBUTE");
            free(__ptr);
            return 0x102;
          }
          goto _L0;
        }
        uVar5 = 0x121;
        goto _L0;
      }
_L0:
      uVar5 = 0x318;
    }
    else {
      if (param_2 == 0x30) {
        __ptr[1] = 0x342;
        sVar4 = strlen(param_3);
        __dest = (char *)malloc(sVar4 + 1);
        strcpy(__dest,param_3);
        goto _L0;
      }
      if (param_2 < 0x31) {
        if (param_2 == 0x20) goto _L0;
        if (param_2 != 0x21) goto _L0;
        uVar5 = 0x520;
      }
      else {
        if (param_2 != 0x31) goto _L0;
        uVar5 = 0x330;
      }
    }
  }
  else {
    if (param_2 != 0x39) {
      if (param_2 < 0x3a) {
        if ((param_2 != 0x36) && (param_2 < 0x37)) {
          if (param_2 != 0x34) goto _L0;
          goto _L0;
        }
      }
      else if (((param_2 != 0x3c) && (0x3c < param_2)) && (param_2 != 0x3d)) {
        if (param_2 != 0x3e) goto _L0;
        __ptr[1] = 0x51b;
        __dest = (char *)malloc(4);
        *(undefined4 *)__dest = *(undefined4 *)param_3;
        goto _L0;
      }
    }
_L0:
    uVar5 = 0x120;
  }
  __ptr[1] = uVar5;
  __dest = (char *)malloc(1);
  *__dest = *param_3;
_L0:
  __ptr[3] = (short)__dest;
  __ptr[2] = 0xffff;
  __ptr[4] = (short)((uint)__dest >> 0x10);
  __ptr[5] = 1;
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar2 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar2 + 0xc) = __ptr;
  }
  return 0;
}

