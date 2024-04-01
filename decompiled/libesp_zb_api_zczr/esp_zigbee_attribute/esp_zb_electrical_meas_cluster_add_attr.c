/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_electrical_meas_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_electrical_meas_cluster_add_attr(int param_1,uint param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  undefined2 *__ptr;
  int iVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  void *__dest;
  undefined2 uVar7;
  int iStack_24;
  
  __ptr = (undefined2 *)malloc(0x10);
  iStack_24 = 0;
  iVar4 = esp_zb_attr_list_get_tail(param_1,0xb04,param_2,&iStack_24);
  iVar2 = iStack_24;
  if (iStack_24 != 0) {
    free(__ptr);
    return iVar2;
  }
  *__ptr = (short)param_2;
  if (param_2 == 0x700) {
    uVar7 = 0x318;
_L0:
    __ptr[1] = uVar7;
    puVar6 = (undefined1 *)malloc(1);
    __ptr[4] = (short)((uint)puVar6 >> 0x10);
    uVar1 = *param_3;
    __ptr[3] = (short)puVar6;
    *puVar6 = uVar1;
    goto _L0;
  }
  if (param_2 < 0x701) {
    if (param_2 == 0x306) {
_L0:
      uVar7 = 0x523;
    }
    else {
      if (0x306 < param_2) {
        if (param_2 < 0x406) {
          if (0x403 < param_2) {
            uVar7 = 0x528;
            goto _L0;
          }
          if (0x401 < param_2) goto _L0;
          if (param_2 < 0x313) goto _L0;
          param_2 = param_2 - 0x400;
          uVar3 = 1;
_L621:
          if (uVar3 < (param_2 & 0xffff)) {
_L0:
            uVar5 = esp_log_timestamp();
            esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC5,uVar5,"ESP_ZIGBEE_ATTRIBUTE");
            free(__ptr);
            return 0x102;
          }
          goto _L0;
        }
        if (param_2 < 0x50e) {
          if (param_2 < 0x50c) {
            if (param_2 < 0x508) {
              if (param_2 < 0x506) {
                if (param_2 < 0x504) {
                  uVar3 = 0x501;
_L633:
                  if (uVar3 < param_2) goto _L0;
                }
                else {
                  uVar3 = 0x505;
                }
_L624:
                if (param_2 != uVar3) goto _L0;
                goto _L0;
              }
            }
            else {
              if (param_2 == 0x50b) goto _L0;
              uVar3 = 0x508;
_L622:
              if (param_2 == uVar3) goto _L0;
            }
            goto _L0;
          }
        }
        else {
          if (0x517 < param_2) {
            param_2 = param_2 - 0x600;
            uVar3 = 5;
            goto _L621;
          }
          if (0x510 < param_2) goto _L0;
          if (param_2 == 0x50f) goto _L0;
          if (param_2 != 0x510) goto _L0;
        }
_L0:
        uVar7 = 0x129;
        goto _L0;
      }
      if (param_2 < 0x109) {
        if (0xff < param_2) {
          uVar3 = 1 << (param_2 - 0x100 & 0x1f);
          if ((uVar3 & 0x1b6) != 0) goto _L0;
          if ((uVar3 & 0x49) == 0) goto _L0;
          goto _L0;
        }
        uVar7 = 0x11b;
        if (param_2 != 0) goto _L0;
      }
      else {
        if (param_2 < 0x304) {
          if (param_2 != 0x303) {
            if (0x300 < param_2) goto _L0;
            if (0x205 < param_2) {
              uVar3 = 0x300;
              goto _L624;
            }
            if (param_2 < 0x200) goto _L0;
          }
          goto _L0;
        }
        uVar7 = 0x52b;
      }
    }
    __ptr[1] = uVar7;
    __dest = malloc(4);
    __ptr[3] = (short)__dest;
    __ptr[4] = (short)((uint)__dest >> 0x10);
    memcpy(__dest,param_3,4);
  }
  else {
    if (param_2 != 0x90b) {
      if (param_2 < 0x90c) {
        if (param_2 < 0x80b) {
          if (param_2 < 0x807) {
            if (param_2 != 0x800) {
              if ((param_2 < 0x801) && (1 < (param_2 - 0x701 & 0xffff))) goto _L0;
              goto _L0;
            }
            uVar7 = 0x319;
            goto _L0;
          }
          uVar7 = 0x329;
          goto _L0;
        }
        if (param_2 < 0x908) {
          uVar3 = 0x905;
          if (0x905 < param_2) {
_L0:
            uVar7 = 0x121;
            goto _L0;
          }
          if (0x903 < param_2) goto _L624;
          if (0x901 < param_2) goto _L0;
          if (param_2 != 0x901) goto _L0;
        }
        else if (param_2 != 0x908) goto _L0;
_L0:
        uVar7 = 0x521;
        goto _L0;
      }
      if (param_2 < 0xa08) {
        if (0xa05 < param_2) goto _L0;
        if (param_2 == 0x910) goto _L0;
        if (0x910 < param_2) {
          if (0x917 < param_2) {
            if (param_2 < 0xa04) {
              uVar3 = 0xa01;
              goto _L633;
            }
            uVar3 = 0xa05;
            goto _L624;
          }
          goto _L0;
        }
        if (param_2 != 0x90e) {
          uVar3 = 0x90f;
_L620:
          if (param_2 != uVar3) goto _L0;
          goto _L0;
        }
      }
      else {
        if (param_2 == 0xa10) {
_L0:
          uVar7 = 0x128;
          goto _L0;
        }
        if (0xa10 < param_2) {
          if (6 < (param_2 - 0xa11 & 0xffff)) goto _L0;
_L0:
          uVar7 = 0x321;
          goto _L0;
        }
        if (param_2 != 0xa0b) {
          if (param_2 < 0xa0c) {
            uVar3 = 0xa08;
            goto _L622;
          }
          if (param_2 != 0xa0e) {
            uVar3 = 0xa0f;
            goto _L620;
          }
        }
      }
    }
_L0:
    uVar7 = 0x529;
_L0:
    __ptr[1] = uVar7;
    puVar6 = (undefined1 *)malloc(2);
    __ptr[4] = (short)((uint)puVar6 >> 0x10);
    uVar1 = *param_3;
    __ptr[3] = (short)puVar6;
    *puVar6 = uVar1;
    puVar6[1] = param_3[1];
  }
_L0:
  __ptr[2] = 0xffff;
  __ptr[5] = 0xb04;
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar4 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar4 + 0xc) = __ptr;
  }
  return 0;
}

