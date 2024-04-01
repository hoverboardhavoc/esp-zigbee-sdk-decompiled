/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_occupancy_sensing_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_occupancy_sensing_cluster_add_attr(int param_1,uint param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 *__ptr;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined2 uVar6;
  uint uVar7;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar3 = esp_zb_attr_list_get_tail(param_1,0x406,param_2,aiStack_24);
  iVar2 = aiStack_24[0];
  if (aiStack_24[0] != 0) {
    free(__ptr);
    return iVar2;
  }
  *__ptr = (short)param_2;
  if (param_2 == 0x20) {
_L0:
    uVar6 = 0x321;
  }
  else {
    if (0x20 < param_2) {
      if (param_2 == 0x30) {
_L0:
        __ptr[1] = 0x321;
        puVar5 = (undefined1 *)malloc(2);
        __ptr[4] = (short)((uint)puVar5 >> 0x10);
        uVar1 = *param_3;
        __ptr[3] = (short)puVar5;
        *puVar5 = uVar1;
        puVar5[1] = param_3[1];
        goto _L0;
      }
      if (param_2 < 0x31) {
        if (param_2 == 0x21) goto _L0;
        uVar7 = 0x22;
      }
      else {
        if (param_2 == 0x31) goto _L0;
        uVar7 = 0x32;
      }
_L662:
      if (param_2 != uVar7) {
_L0:
        uVar4 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC5,uVar4,"ESP_ZIGBEE_ATTRIBUTE");
        free(__ptr);
        return 0x102;
      }
      uVar6 = 800;
_L657:
      __ptr[1] = uVar6;
      puVar5 = (undefined1 *)malloc(1);
      __ptr[4] = (short)((uint)puVar5 >> 0x10);
      uVar1 = *param_3;
      __ptr[3] = (short)puVar5;
      *puVar5 = uVar1;
      goto _L0;
    }
    if (param_2 == 0x10) goto _L0;
    if (param_2 < 0x11) {
      if (param_2 == 1) {
        uVar6 = 0x130;
      }
      else if (param_2 == 2) {
        uVar6 = 0x118;
      }
      else {
        uVar6 = 0x518;
        if (param_2 != 0) goto _L0;
      }
      goto _L657;
    }
    if (param_2 != 0x11) {
      uVar7 = 0x12;
      goto _L662;
    }
    uVar6 = 0x329;
  }
  __ptr[1] = uVar6;
  puVar5 = (undefined1 *)malloc(2);
  __ptr[4] = (short)((uint)puVar5 >> 0x10);
  uVar1 = *param_3;
  __ptr[3] = (short)puVar5;
  *puVar5 = uVar1;
  puVar5[1] = param_3[1];
_L0:
  __ptr[2] = 0xffff;
  __ptr[5] = 0x406;
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar3 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar3 + 0xc) = __ptr;
  }
  return 0;
}

