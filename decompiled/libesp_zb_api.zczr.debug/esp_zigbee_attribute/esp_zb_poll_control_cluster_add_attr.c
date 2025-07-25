/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_attribute.o -> esp_zb_poll_control_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_poll_control_cluster_add_attr(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 == 4) {
    uVar2 = 1;
    uVar1 = 0x23;
  }
  else if (param_1 < 5) {
    if (param_1 == 2) {
      uVar2 = 1;
      uVar1 = 0x21;
    }
    else if (param_1 < 3) {
      if (param_1 == 0) {
        uVar2 = 3;
        uVar1 = 0x23;
      }
      else {
        if (param_1 != 1) goto _L0;
        uVar2 = 1;
        uVar1 = 0x23;
      }
    }
    else {
      if (param_1 != 3) goto _L0;
      uVar2 = 3;
      uVar1 = 0x21;
    }
  }
  else if (param_1 == 0xeffe) {
    uVar2 = 0x40;
    uVar1 = 4;
  }
  else if (param_1 < 0xefff) {
    if (param_1 == 5) {
      uVar2 = 1;
      uVar1 = 0x23;
    }
    else {
      if (param_1 != 6) goto _L0;
      uVar2 = 1;
      uVar1 = 0x21;
    }
  }
  else {
    if (param_1 != 0xefff) {
_L0:
      uVar1 = esp_log_timestamp(param_2);
      esp_log_write(1,0x10000,&_LC11,uVar1,0x10000);
      return 0x102;
    }
    uVar2 = 0x40;
    uVar1 = 3;
  }
  uVar1 = esp_zb_internal_cluster_add_attr(0x20,param_1,uVar1,uVar2,0xffff);
  return uVar1;
}

