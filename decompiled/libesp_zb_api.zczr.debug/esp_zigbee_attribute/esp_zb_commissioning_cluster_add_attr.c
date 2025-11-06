/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_attribute.o -> esp_zb_commissioning_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_commissioning_cluster_add_attr(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0x13) {
    uVar1 = 0x10;
  }
  else if (param_1 < 0x14) {
    if (param_1 == 5) {
      uVar1 = 0x20;
    }
    else if (param_1 < 6) {
      if (param_1 == 3) {
        uVar1 = 0x1b;
      }
      else if (param_1 < 4) {
        if (param_1 == 1) {
          uVar1 = 0xf0;
        }
        else if (param_1 == 2) {
          uVar1 = 0x21;
        }
        else {
          if (param_1 != 0) goto _L0;
          uVar1 = 0x21;
        }
      }
      else {
        if (param_1 != 4) goto _L0;
        uVar1 = 0x20;
      }
    }
    else if (param_1 == 0x11) {
      uVar1 = 0xf1;
    }
    else if (param_1 < 0x12) {
      if (param_1 == 6) {
        uVar1 = 0x30;
      }
      else {
        if (param_1 != 0x10) goto _L0;
        uVar1 = 0xf0;
      }
    }
    else {
      if (param_1 != 0x12) {
_L0:
        uVar1 = esp_log_timestamp(param_2);
        esp_log(1,0x10000,"E (%lu) %s: incorrect/unsupported attribute_id!\n",uVar1,0x10000);
        return 0x102;
      }
      uVar1 = 0xf1;
    }
  }
  else if (param_1 == 0x20) {
    uVar1 = 0x20;
  }
  else if (param_1 < 0x21) {
    if (param_1 == 0x15) {
      uVar1 = 0x20;
    }
    else if (param_1 < 0x16) {
      if (param_1 != 0x14) goto _L0;
      uVar1 = 0xf1;
    }
    else if (param_1 == 0x16) {
      uVar1 = 0x30;
    }
    else {
      if (param_1 != 0x17) goto _L0;
      uVar1 = 0x21;
    }
  }
  else if (param_1 == 0x41) {
    uVar1 = 0x20;
  }
  else if (param_1 < 0x42) {
    if (param_1 == 0x21) {
      uVar1 = 0x21;
    }
    else {
      if (param_1 != 0x40) goto _L0;
      uVar1 = 0x10;
    }
  }
  else {
    if (param_1 != 0x42) goto _L0;
    uVar1 = 0x20;
  }
  uVar1 = esp_zb_internal_cluster_add_attr(0x15,param_1,uVar1,3,0xffff);
  return uVar1;
}

