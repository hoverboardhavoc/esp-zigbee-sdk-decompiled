/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_common.o -> esp_zb_zcl_put_attribute_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 *
esp_zb_zcl_put_attribute_value(undefined1 *param_1,uint param_2,undefined1 *param_3,size_t param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  uint uVar9;
  
  if (param_4 == 0xffff) {
    uVar8 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: %s(%d): Invalid value size\n",uVar8,0x10000,
            "esp_zb_zcl_put_attribute_value",0x35);
    return param_1;
  }
  if (param_2 == 0x25) {
_L0:
    uVar1 = param_3[1];
    uVar2 = param_3[2];
    uVar3 = param_3[3];
    uVar4 = param_3[4];
    uVar5 = param_3[5];
    *param_1 = *param_3;
    param_1[1] = uVar1;
    param_1[2] = uVar2;
    param_1[3] = uVar3;
    param_1[4] = uVar4;
    param_1[5] = uVar5;
    return param_1 + 6;
  }
  if (param_2 < 0x26) {
    if (param_2 == 0x10) {
_L0:
      *param_1 = *param_3;
      return param_1 + 1;
    }
    if (param_2 < 0x11) {
      if (param_2 == 10) {
_L0:
        *param_1 = *param_3;
        param_1[1] = param_3[1];
        param_1[2] = param_3[2];
        return param_1 + 3;
      }
      if (param_2 < 0xb) {
        if (param_2 == 0) {
          return param_1;
        }
        if (param_2 == 8) goto _L0;
        if (param_2 == 9) goto _L0;
      }
      else {
        if (param_2 == 0xd) goto _L0;
        if (param_2 < 0xe) {
          if (param_2 == 0xb) goto _L0;
          if (param_2 == 0xc) goto _L0;
        }
        else {
          if (param_2 == 0xe) goto _L0;
          if (param_2 == 0xf) goto _L0;
        }
      }
    }
    else {
      if (param_2 == 0x1e) {
_L0:
        uVar1 = param_3[1];
        uVar2 = param_3[2];
        uVar3 = param_3[3];
        uVar4 = param_3[4];
        uVar5 = param_3[5];
        uVar6 = param_3[6];
        *param_1 = *param_3;
        param_1[1] = uVar1;
        param_1[2] = uVar2;
        param_1[3] = uVar3;
        param_1[4] = uVar4;
        param_1[5] = uVar5;
        param_1[6] = uVar6;
        return param_1 + 7;
      }
      if (param_2 < 0x1f) {
        if (param_2 == 0x1b) goto _L0;
        if (param_2 < 0x1c) {
          if (param_2 == 0x19) {
_L0:
            *param_1 = *param_3;
            param_1[1] = param_3[1];
            return param_1 + 2;
          }
          if (param_2 == 0x1a) goto _L0;
          if (param_2 == 0x18) goto _L0;
        }
        else {
          if (param_2 == 0x1c) {
_L0:
            uVar1 = param_3[1];
            uVar2 = param_3[2];
            uVar3 = param_3[3];
            uVar4 = param_3[4];
            *param_1 = *param_3;
            param_1[1] = uVar1;
            param_1[2] = uVar2;
            param_1[3] = uVar3;
            param_1[4] = uVar4;
            return param_1 + 5;
          }
          if (param_2 == 0x1d) goto _L0;
        }
      }
      else {
        if (param_2 == 0x22) goto _L0;
        if (param_2 < 0x23) {
          if (param_2 == 0x20) goto _L0;
          if (param_2 == 0x21) goto _L0;
          if (param_2 == 0x1f) goto _L0;
        }
        else {
          if (param_2 == 0x23) goto _L0;
          if (param_2 == 0x24) goto _L0;
        }
      }
    }
  }
  else if (param_2 < 0x52) {
    if (param_2 < 0x39) {
      if (param_2 == 0x2c) goto _L0;
      if (param_2 < 0x2d) {
        if (param_2 == 0x28) goto _L0;
        if (param_2 < 0x29) {
          if (param_2 == 0x26) goto _L0;
          if (param_2 == 0x27) goto _L0;
        }
        else {
          if (param_2 == 0x2a) goto _L0;
          if (param_2 == 0x2b) goto _L0;
          if (param_2 == 0x29) goto _L0;
        }
      }
      else {
        if (param_2 == 0x2f) goto _L0;
        if (param_2 < 0x30) {
          if (param_2 == 0x2d) goto _L0;
          if (param_2 == 0x2e) goto _L0;
        }
        else {
          if ((param_2 == 0x31) || (param_2 == 0x38)) goto _L0;
          if (param_2 == 0x30) goto _L0;
        }
      }
    }
    else {
      uVar9 = 1 << (param_2 - 0x39 & 0x1f);
      if ((uVar9 & 0x18b8f00) != 0) {
        memcpy(param_1,param_3,param_4);
        return param_1 + param_4;
      }
      if ((uVar9 & 2) != 0) {
_L0:
        uVar1 = param_3[1];
        uVar2 = param_3[2];
        uVar3 = param_3[3];
        uVar4 = param_3[4];
        uVar5 = param_3[5];
        uVar6 = param_3[6];
        uVar7 = param_3[7];
        *param_1 = *param_3;
        param_1[1] = uVar1;
        param_1[2] = uVar2;
        param_1[3] = uVar3;
        param_1[4] = uVar4;
        param_1[5] = uVar5;
        param_1[6] = uVar6;
        param_1[7] = uVar7;
        return param_1 + 8;
      }
      if ((uVar9 & 1) != 0) goto _L0;
    }
  }
  else {
    if (param_2 == 0xf1) {
      memcpy(param_1,param_3,0x10);
      return param_1 + 0x10;
    }
    if (param_2 < 0xf2) {
      if (param_2 == 0xea) {
_L0:
        uVar1 = param_3[1];
        uVar2 = param_3[2];
        uVar3 = param_3[3];
        *param_1 = *param_3;
        param_1[1] = uVar1;
        param_1[2] = uVar2;
        param_1[3] = uVar3;
        return param_1 + 4;
      }
      if (param_2 < 0xeb) {
        if (param_2 < 0xe3) {
          if (0xdf < param_2) goto _L0;
        }
        else if ((param_2 + 0x18 & 0xff) < 2) goto _L0;
      }
      else if (param_2 == 0xf0) goto _L0;
    }
  }
  uVar8 = esp_log_timestamp();
  esp_log(2,0x10000,"W (%lu) %s: Unsupported data type (0x%x)!\n",uVar8,0x10000,param_2);
  return param_1;
}

