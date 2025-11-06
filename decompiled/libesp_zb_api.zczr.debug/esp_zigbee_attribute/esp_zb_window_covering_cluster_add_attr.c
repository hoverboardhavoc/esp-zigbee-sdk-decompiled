/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_attribute.o -> esp_zb_window_covering_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_window_covering_cluster_add_attr(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 < 0x14) {
    if (param_1 < 0x10) {
      if (param_1 == 7) {
        uVar2 = 1;
        uVar1 = 0x18;
      }
      else if (param_1 < 8) {
        if (param_1 == 0) {
          uVar2 = 1;
          uVar1 = 0x30;
        }
        else {
          if (5 < (param_1 - 1 & 0xffff)) goto _L0;
          uVar2 = 1;
          uVar1 = 0x21;
        }
      }
      else {
        if (1 < (param_1 - 8 & 0xffff)) goto _L0;
        uVar2 = 0x15;
        uVar1 = 0x20;
      }
    }
    else {
      uVar2 = 1;
      uVar1 = 0x21;
    }
  }
  else if (param_1 == 0x17) {
    uVar2 = 3;
    uVar1 = 0x18;
  }
  else if (param_1 < 0x18) {
    if (2 < (param_1 - 0x14 & 0xffff)) {
_L0:
      uVar1 = esp_log_timestamp(param_2);
      esp_log(1,0x10000,"E (%lu) %s: incorrect/unsupported attribute_id!\n",uVar1,0x10000);
      return 0x102;
    }
    uVar2 = 3;
    uVar1 = 0x21;
  }
  else {
    if (1 < (param_1 - 0x18 & 0xffff)) goto _L0;
    uVar2 = 3;
    uVar1 = 0x41;
  }
  uVar1 = esp_zb_internal_cluster_add_attr(0x102,param_1,uVar1,uVar2,0xffff);
  return uVar1;
}

