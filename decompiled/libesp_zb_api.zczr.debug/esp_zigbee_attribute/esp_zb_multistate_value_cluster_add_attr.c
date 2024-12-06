/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_attribute.o -> esp_zb_multistate_value_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_multistate_value_cluster_add_attr(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 == 0x67) {
    uVar2 = 1;
    uVar1 = 0x30;
  }
  else if (param_1 < 0x68) {
    if (param_1 == 0x51) {
      uVar2 = 1;
      uVar1 = 0x10;
    }
    else if (param_1 == 0x55) {
      uVar2 = 3;
      uVar1 = 0x21;
    }
    else {
      if (param_1 != 0x1c) {
_L0:
        uVar1 = esp_log_timestamp(param_2);
        esp_log_write(1,0x10000,&_LC11,uVar1,0x10000);
        return 0x102;
      }
      uVar2 = 1;
      uVar1 = 0x42;
    }
  }
  else if (param_1 == 0x6f) {
    uVar2 = 1;
    uVar1 = 0x18;
  }
  else if (param_1 == 0x100) {
    uVar2 = 1;
    uVar1 = 0x23;
  }
  else {
    if (param_1 != 0x68) goto _L0;
    uVar2 = 1;
    uVar1 = 0x21;
  }
  uVar1 = esp_zb_internal_cluster_add_attr(0x14,param_1,uVar1,uVar2,0xffff);
  return uVar1;
}

