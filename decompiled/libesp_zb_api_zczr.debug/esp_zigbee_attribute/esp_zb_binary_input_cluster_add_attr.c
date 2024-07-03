/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_binary_input_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_binary_input_cluster_add_attr(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 == 0x55) {
    uVar2 = 5;
    uVar1 = 0x10;
  }
  else if (param_1 < 0x56) {
    if (param_1 == 0x51) {
      uVar2 = 1;
      uVar1 = 0x10;
    }
    else if (param_1 < 0x52) {
      if (param_1 == 0x1c) {
        uVar2 = 1;
        uVar1 = 0x42;
      }
      else if (param_1 == 0x2e) {
        uVar2 = 1;
        uVar1 = 0x42;
      }
      else {
        if (param_1 != 4) goto _L0;
        uVar2 = 1;
        uVar1 = 0x42;
      }
    }
    else {
      if (param_1 != 0x54) {
_L0:
        uVar2 = esp_log_timestamp(param_2);
        esp_log_write(1,0x10000,&_LC11,uVar2,0x10000);
        return 0x102;
      }
      uVar2 = 1;
      uVar1 = 0x18;
    }
  }
  else if (param_1 == 0x6f) {
    uVar2 = 5;
    uVar1 = 0x18;
  }
  else if (param_1 == 0x100) {
    uVar2 = 1;
    uVar1 = 0x23;
  }
  else {
    if (param_1 != 0x67) goto _L0;
    uVar2 = 1;
    uVar1 = 0x18;
  }
  uVar2 = esp_zb_internal_cluster_add_attr(0xf,param_1,uVar1,uVar2,0xffff);
  return uVar2;
}

