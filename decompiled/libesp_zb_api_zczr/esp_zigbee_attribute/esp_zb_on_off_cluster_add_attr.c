/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_on_off_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_on_off_cluster_add_attr(int param_1,uint param_2,undefined2 *param_3)

{
  int iVar1;
  undefined2 *__ptr;
  int iVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  undefined2 uVar5;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar2 = esp_zb_attr_list_get_tail(param_1,6,param_2,aiStack_24);
  iVar1 = aiStack_24[0];
  if (aiStack_24[0] != 0) {
    free(__ptr);
    return iVar1;
  }
  *__ptr = (short)param_2;
  if (param_2 == 0x4001) {
_L0:
    __ptr[1] = 0x321;
    puVar4 = (undefined2 *)malloc(2);
    *puVar4 = *param_3;
  }
  else {
    if (param_2 < 0x4002) {
      if (param_2 == 0) {
        uVar5 = 0x1510;
      }
      else {
        if (param_2 != 0x4000) {
_L0:
          uVar3 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC5,uVar3,"ESP_ZIGBEE_ATTRIBUTE");
          free(__ptr);
          return 0x102;
        }
        uVar5 = 0x110;
      }
    }
    else {
      if (param_2 == 0x4002) goto _L0;
      if (param_2 != 0x4003) goto _L0;
      uVar5 = 0x330;
    }
    __ptr[1] = uVar5;
    puVar4 = (undefined2 *)malloc(1);
    *(undefined1 *)puVar4 = *(undefined1 *)param_3;
  }
  __ptr[4] = (short)((uint)puVar4 >> 0x10);
  __ptr[2] = 0xffff;
  __ptr[3] = (short)puVar4;
  __ptr[5] = 6;
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar2 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar2 + 0xc) = __ptr;
  }
  return 0;
}

