/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_color_control_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_color_control_cluster_add_attr(int param_1,uint param_2,undefined2 *param_3)

{
  int iVar1;
  undefined2 *__ptr;
  int iVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar2 = esp_zb_attr_list_get_tail(param_1,0x300,param_2,aiStack_24);
  iVar1 = aiStack_24[0];
  if (aiStack_24[0] != 0) {
    free(__ptr);
    return iVar1;
  }
  *__ptr = (short)param_2;
  if (param_2 == 0x4002) {
_L0:
    uVar5 = 0x1120;
_L0:
    __ptr[1] = uVar5;
    puVar3 = (undefined2 *)malloc(1);
    *(undefined1 *)puVar3 = *(undefined1 *)param_3;
  }
  else {
    if (param_2 < 0x4003) {
      if (param_2 != 7) {
        if (param_2 < 8) {
          if (param_2 == 2) goto _L0;
          if (2 < param_2) {
            if ((param_2 != 3) && (param_2 != 4)) goto _L0;
            goto _L0;
          }
          if (param_2 == 0) {
            uVar5 = 0x520;
          }
          else {
            uVar5 = 0x1520;
          }
        }
        else {
          if (param_2 == 0x4000) {
_L0:
            uVar5 = 0x1121;
            goto _L0;
          }
          if ((param_2 == 0x4001) || (param_2 == 8)) {
            uVar5 = 0x130;
          }
          else {
            if (param_2 != 0xf) goto _L0;
            uVar5 = 0x318;
          }
        }
        goto _L0;
      }
_L0:
      uVar5 = 0x1521;
    }
    else if (param_2 == 0x400a) {
      uVar5 = 0x119;
    }
    else {
      if (param_2 < 0x400b) {
        if (param_2 != 0x4005) {
          if (param_2 < 0x4006) {
            if (param_2 != 0x4003) goto _L0;
            goto _L0;
          }
          if (param_2 != 0x4006) goto _L0;
        }
      }
      else if ((param_2 != 0x400d) && (0x400d < param_2)) {
        if (param_2 != 0x4010) {
_L0:
          uVar4 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC5,uVar4,"ESP_ZIGBEE_ATTRIBUTE");
          free(__ptr);
          return 0x102;
        }
        uVar5 = 0x321;
        goto _L0;
      }
_L0:
      uVar5 = 0x121;
    }
_L0:
    __ptr[1] = uVar5;
    puVar3 = (undefined2 *)malloc(2);
    *puVar3 = *param_3;
  }
  __ptr[3] = (short)puVar3;
  __ptr[2] = 0xffff;
  __ptr[4] = (short)((uint)puVar3 >> 0x10);
  __ptr[5] = 0x300;
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar2 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar2 + 0xc) = __ptr;
  }
  return 0;
}

