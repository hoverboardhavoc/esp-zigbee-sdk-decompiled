/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_attribute.o -> esp_zb_ias_zone_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ias_zone_cluster_add_attr(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 == 0x12) {
    uVar2 = 1;
    uVar1 = 0x20;
  }
  else if (param_1 < 0x13) {
    if (param_1 == 2) {
      uVar2 = 1;
      uVar1 = 0x19;
    }
    else if (param_1 < 3) {
      if (param_1 == 0) {
        uVar2 = 1;
        uVar1 = 0x30;
      }
      else {
        if (param_1 != 1) goto _L0;
        uVar2 = 1;
        uVar1 = 0x31;
      }
    }
    else if (param_1 == 0x10) {
      uVar2 = 3;
      uVar1 = 0xf0;
    }
    else {
      if (param_1 != 0x11) goto _L0;
      uVar2 = 1;
      uVar1 = 0x20;
    }
  }
  else if (param_1 == 0xe001) {
    uVar2 = 0x40;
    uVar1 = 1;
  }
  else if (param_1 < 0xe002) {
    if (param_1 == 0x13) {
      uVar2 = 3;
      uVar1 = 0x20;
    }
    else {
      if (param_1 != 0xe000) {
_L0:
        uVar1 = esp_log_timestamp(param_2);
        esp_log(1,0x10000,"E (%lu) %s: incorrect/unsupported attribute_id!\n",uVar1,0x10000);
        return 0x102;
      }
      uVar2 = 0x40;
      uVar1 = 1;
    }
  }
  else if (param_1 == 0xe002) {
    uVar2 = 0x40;
    uVar1 = 2;
  }
  else {
    if (param_1 != 0xeffe) goto _L0;
    uVar2 = 0x40;
    uVar1 = 0xc;
  }
  uVar1 = esp_zb_internal_cluster_add_attr(0x500,param_1,uVar1,uVar2,0xffff);
  return uVar1;
}

