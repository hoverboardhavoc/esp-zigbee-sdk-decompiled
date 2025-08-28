/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_attribute.o -> esp_zb_multistate_output_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_multistate_output_cluster_add_attr(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 == 0x55) {
    uVar2 = 7;
    uVar1 = 0x21;
  }
  else if (param_1 < 0x56) {
    if (param_1 == 0x4a) {
      uVar2 = 3;
      uVar1 = 0x21;
    }
    else if (param_1 < 0x4b) {
      if (param_1 == 0xe) {
        uVar2 = 3;
        uVar1 = 0x48;
      }
      else {
        if (param_1 != 0x1c) {
          return 0x102;
        }
        uVar2 = 3;
        uVar1 = 0x42;
      }
    }
    else {
      if (param_1 != 0x51) {
        return 0x102;
      }
      uVar2 = 3;
      uVar1 = 0x10;
    }
  }
  else if (param_1 == 0x6f) {
    uVar2 = 5;
    uVar1 = 0x18;
  }
  else if (param_1 < 0x70) {
    if (param_1 == 0x67) {
      uVar2 = 3;
      uVar1 = 0x30;
    }
    else {
      if (param_1 != 0x68) {
        return 0x102;
      }
      uVar2 = 3;
      uVar1 = 0x21;
    }
  }
  else {
    if (param_1 != 0x100) {
      return 0x102;
    }
    uVar2 = 1;
    uVar1 = 0x23;
  }
  uVar1 = esp_zb_internal_cluster_add_attr(0x13,param_1,uVar1,uVar2,param_2,0xffff);
  return uVar1;
}

