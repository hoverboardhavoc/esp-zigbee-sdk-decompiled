/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_put_attribute_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 *
esp_zb_zcl_put_attribute_value(undefined1 *param_1,int param_2,undefined1 *param_3,size_t param_4)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined4 uVar9;
  
  bVar1 = *(byte *)(param_2 + 2);
  if (bVar1 != 0x2f) {
    if (0x2f < bVar1) {
      if (bVar1 == 0x48) {
_L0:
        memcpy(param_1,param_3,param_4);
        return param_1 + param_4;
      }
      if (bVar1 < 0x49) {
        if (bVar1 == 0x39) goto _L0;
        if (bVar1 < 0x3a) {
          if ((bVar1 == 0x31) || (bVar1 == 0x38)) goto _L0;
          if (bVar1 == 0x30) goto _L0;
        }
        else {
          if (bVar1 == 0x3a) goto _L0;
          if ((0x39 < bVar1) && ((byte)(bVar1 + 0xbf) < 3)) goto _L0;
        }
      }
      else if (bVar1 < 0xe3) {
        if (0xdf < bVar1) {
_L0:
          uVar2 = param_3[1];
          uVar3 = param_3[2];
          uVar4 = param_3[3];
          *param_1 = *param_3;
          param_1[1] = uVar2;
          param_1[2] = uVar3;
          param_1[3] = uVar4;
          return param_1 + 4;
        }
        if (bVar1 == 0x4a) goto _L0;
      }
      else {
        if (bVar1 == 0xea) goto _L0;
        if (bVar1 < 0xeb) {
          if ((byte)(bVar1 + 0x18) < 2) goto _L0;
        }
        else if (bVar1 == 0xf0) goto _L0;
      }
_L0:
      uVar9 = esp_log_timestamp();
      esp_log_write(2,0x10000,&_LC1,uVar9,0x10000);
      return param_1;
    }
    if (bVar1 != 0x1f) {
      if (bVar1 < 0x20) {
        if (bVar1 == 0x10) {
_L0:
          *param_1 = *param_3;
          return param_1 + 1;
        }
        if (bVar1 < 0x11) {
          if (bVar1 != 0xb) {
            if (bVar1 < 0xc) {
              if (bVar1 == 8) goto _L0;
              if (bVar1 == 9) goto _L0;
            }
            else if (bVar1 == 0xf) goto _L0;
            goto _L0;
          }
        }
        else {
          if (bVar1 == 0x19) goto _L0;
          if (bVar1 != 0x1b) {
            if (bVar1 != 0x18) goto _L0;
            goto _L0;
          }
        }
        goto _L0;
      }
      if (bVar1 != 0x27) {
        if (bVar1 < 0x28) {
          if (bVar1 != 0x21) {
            if (bVar1 == 0x23) goto _L0;
            if (bVar1 == 0x20) goto _L0;
            goto _L0;
          }
        }
        else if (bVar1 != 0x29) {
          if (bVar1 == 0x2b) goto _L0;
          if (bVar1 == 0x28) goto _L0;
          goto _L0;
        }
_L0:
        *param_1 = *param_3;
        param_1[1] = param_3[1];
        return param_1 + 2;
      }
    }
  }
_L0:
  uVar2 = param_3[1];
  uVar3 = param_3[2];
  uVar4 = param_3[3];
  uVar5 = param_3[4];
  uVar6 = param_3[5];
  uVar7 = param_3[6];
  uVar8 = param_3[7];
  *param_1 = *param_3;
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar4;
  param_1[4] = uVar5;
  param_1[5] = uVar6;
  param_1[6] = uVar7;
  param_1[7] = uVar8;
  return param_1 + 8;
}

