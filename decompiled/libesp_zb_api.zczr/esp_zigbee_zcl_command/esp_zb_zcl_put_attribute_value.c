/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_put_attribute_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 *
esp_zb_zcl_put_attribute_value(undefined1 *param_1,uint param_2,undefined1 *param_3,size_t param_4)

{
  uint uVar1;
  
  if (param_4 == 0xffff) {
    return param_1;
  }
  if (param_2 == 0x27) goto _L0;
  if (param_2 < 0x28) {
    if (param_2 == 0x1b) goto _L0;
    if (0x1b < param_2) {
      if (param_2 == 0x21) goto _L0;
      if (param_2 < 0x22) {
        if (param_2 != 0x1e) {
          if (0x1e < param_2) {
            if (param_2 == 0x1f) goto _L0;
            goto _L0;
          }
          if (param_2 != 0x1c) goto _L0;
          goto _L0;
        }
        goto _L0;
      }
      if (param_2 != 0x24) {
        if (param_2 < 0x25) {
          if (param_2 == 0x22) goto _L0;
          goto _L0;
        }
        if (param_2 == 0x25) goto _L0;
        goto _L0;
      }
      goto _L0;
    }
    if (param_2 == 0xd) {
_L0:
      memcpy(param_1,param_3,6);
      return param_1 + 6;
    }
    if (0xd < param_2) {
      if (param_2 == 0x10) {
_L0:
        *param_1 = *param_3;
        return param_1 + 1;
      }
      if (0x10 < param_2) {
        if (param_2 == 0x19) goto _L0;
        if (param_2 == 0x1a) goto _L0;
        if (param_2 != 0x18) {
          return param_1;
        }
        goto _L0;
      }
      uVar1 = 0xe;
_L52:
      if (param_2 == uVar1) {
_L0:
        memcpy(param_1,param_3,7);
        return param_1 + 7;
      }
_L0:
      memcpy(param_1,param_3,8);
      return param_1 + 8;
    }
    if (param_2 == 10) {
_L0:
      memcpy(param_1,param_3,3);
      return param_1 + 3;
    }
    if (param_2 < 0xb) {
      if (param_2 == 8) goto _L0;
      uVar1 = 9;
_L54:
      if (param_2 != uVar1) {
        return param_1;
      }
_L0:
      *param_1 = *param_3;
      param_1[1] = param_3[1];
      return param_1 + 2;
    }
    uVar1 = 0xb;
  }
  else {
    if (0x51 < param_2) {
      if (param_2 == 0xf1) {
        memcpy(param_1,param_3,0x10);
        return param_1 + 0x10;
      }
      if (0xf1 < param_2) {
        return param_1;
      }
      if (param_2 != 0xea) {
        if (0xea < param_2) {
          if (param_2 != 0xf0) {
            return param_1;
          }
          goto _L0;
        }
        if (0xe2 < param_2) {
          if (1 < (param_2 + 0x18 & 0xff)) {
            return param_1;
          }
          goto _L0;
        }
        if (param_2 < 0xe0) {
          return param_1;
        }
      }
      goto _L0;
    }
    if (0x38 < param_2) {
      uVar1 = 1 << (param_2 - 0x39 & 0x1f);
      if ((uVar1 & 0x18b8f00) != 0) {
        memcpy(param_1,param_3,param_4);
        return param_1 + param_4;
      }
      if (param_2 == 0x3a) goto _L0;
      if ((uVar1 & 1) == 0) {
        return param_1;
      }
      goto _L0;
    }
    if (param_2 == 0x2d) goto _L0;
    if (0x2d < param_2) {
      if (param_2 == 0x30) goto _L0;
      if (0x30 < param_2) {
        if (param_2 == 0x31) goto _L0;
        uVar1 = 0x38;
        goto _L54;
      }
      uVar1 = 0x2e;
      goto _L52;
    }
    if (param_2 == 0x2a) goto _L0;
    if (param_2 < 0x2b) {
      if (param_2 != 0x28) goto _L0;
      goto _L0;
    }
    uVar1 = 0x2b;
  }
  if (param_2 != uVar1) {
_L0:
    memcpy(param_1,param_3,5);
    return param_1 + 5;
  }
_L0:
  memcpy(param_1,param_3,4);
  return param_1 + 4;
}

