/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_door_lock_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_door_lock_cluster_add_attr(int param_1,uint param_2,char *param_3)

{
  int iVar1;
  undefined2 *__ptr;
  int iVar2;
  undefined4 uVar3;
  char *__dest;
  size_t sVar4;
  undefined2 uVar5;
  uint uVar6;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar2 = esp_zb_attr_list_get_tail(param_1,0x101,param_2,aiStack_24);
  iVar1 = aiStack_24[0];
  if (aiStack_24[0] != 0) {
    free(__ptr);
    return iVar1;
  }
  *__ptr = (short)param_2;
  if (param_2 == 0x23) {
    uVar5 = 0x723;
_L0:
    __ptr[1] = uVar5;
    __dest = (char *)malloc(4);
    *(undefined4 *)__dest = *(undefined4 *)param_3;
    goto _L0;
  }
  if (param_2 < 0x24) {
    if (param_2 == 0x13) {
_L0:
      uVar5 = 0x121;
      goto _L0;
    }
    if (0x13 < param_2) {
      if ((param_2 != 0x19) && (0x19 < param_2)) {
        if (param_2 == 0x21) {
          __ptr[1] = 0x742;
          sVar4 = strlen(param_3);
          __dest = (char *)malloc(sVar4 + 1);
          strcpy(__dest,param_3);
          goto _L0;
        }
        if (param_2 == 0x22) goto _L0;
        if (param_2 != 0x1a) {
          uVar6 = 0x20;
_L412:
          if (param_2 != uVar6) {
_L0:
            uVar3 = esp_log_timestamp();
            esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC5,uVar3,"ESP_ZIGBEE_ATTRIBUTE");
            free(__ptr);
            return 0x102;
          }
          goto _L0;
        }
      }
      uVar5 = 0x120;
      goto _L0;
    }
    if (param_2 == 5) {
_L0:
      uVar5 = 0x323;
      goto _L0;
    }
    if (5 < param_2) {
      if ((param_2 != 0x11) && (param_2 != 0x12)) {
        if (param_2 == 6) {
          uVar5 = 0x321;
          goto _L0;
        }
        if (param_2 != 0x10) goto _L0;
      }
      goto _L0;
    }
    if (param_2 == 2) {
      uVar5 = 0x110;
    }
    else {
      if (param_2 < 3) {
        uVar5 = 0x130;
        if (param_2 != 0) goto _L0;
      }
      else if (param_2 != 3) goto _L0;
_L0:
      uVar5 = 0x530;
    }
  }
  else {
    if (param_2 != 0x32) {
      if (0x32 < param_2) {
        if (param_2 != 0x43) {
          if (param_2 < 0x44) {
            if ((param_2 != 0x40) && (param_2 < 0x41)) {
              if (param_2 != 0x33) {
                if (param_2 != 0x34) goto _L0;
                goto _L0;
              }
              goto _L0;
            }
          }
          else if (((param_2 != 0x46) && (0x46 < param_2)) && (param_2 != 0x47)) goto _L0;
        }
        uVar5 = 0x719;
_L0:
        __ptr[1] = uVar5;
        __dest = (char *)malloc(2);
        *(undefined2 *)__dest = *(undefined2 *)param_3;
        goto _L0;
      }
      if (param_2 != 0x29) {
        if (param_2 < 0x2a) {
          if (param_2 == 0x26) {
            uVar5 = 0x119;
          }
          else {
            if (param_2 < 0x27) {
              if (param_2 != 0x24) {
                uVar5 = 0x730;
                goto _L0;
              }
              goto _L0;
            }
            if (param_2 != 0x27) goto _L0;
            uVar5 = 0x519;
          }
          goto _L0;
        }
        if ((param_2 == 0x30) || (param_2 == 0x31)) {
_L0:
          uVar5 = 0x720;
          goto _L0;
        }
        if (param_2 != 0x2a) {
          uVar6 = 0x2b;
          goto _L412;
        }
      }
    }
_L0:
    uVar5 = 0x710;
  }
_L0:
  __ptr[1] = uVar5;
  __dest = (char *)malloc(1);
  *__dest = *param_3;
_L0:
  __ptr[3] = (short)__dest;
  __ptr[2] = 0xffff;
  __ptr[4] = (short)((uint)__dest >> 0x10);
  __ptr[5] = 0x101;
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar2 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar2 + 0xc) = __ptr;
  }
  return 0;
}

