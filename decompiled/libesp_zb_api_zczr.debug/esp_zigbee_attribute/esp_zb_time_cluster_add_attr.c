/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_time_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_time_cluster_add_attr(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 == 5) {
    uVar2 = 3;
    uVar1 = 0x2b;
  }
  else if (param_1 < 6) {
    if (param_1 == 2) {
      uVar2 = 3;
      uVar1 = 0x2b;
    }
    else if (param_1 < 3) {
      if (param_1 == 0) {
        uVar2 = 3;
        uVar1 = 0xe2;
      }
      else {
        if (param_1 != 1) goto _L0;
        uVar2 = 3;
        uVar1 = 0x18;
      }
    }
    else if (param_1 == 3) {
      uVar2 = 3;
      uVar1 = 0x23;
    }
    else {
      if (param_1 != 4) goto _L0;
      uVar2 = 3;
      uVar1 = 0x23;
    }
  }
  else if (param_1 == 7) {
    uVar2 = 1;
    uVar1 = 0x23;
  }
  else if (param_1 < 8) {
    if (param_1 != 6) {
_L0:
      uVar1 = esp_log_timestamp(param_2);
      esp_log_write(1,0x10000,&_LC11,uVar1,0x10000);
      return 0x102;
    }
    uVar2 = 1;
    uVar1 = 0x23;
  }
  else if (param_1 == 8) {
    uVar2 = 1;
    uVar1 = 0xe2;
  }
  else {
    if (param_1 != 9) goto _L0;
    uVar2 = 3;
    uVar1 = 0xe2;
  }
  uVar1 = esp_zb_internal_cluster_add_attr(10,param_1,uVar1,uVar2,0xffff);
  return uVar1;
}

