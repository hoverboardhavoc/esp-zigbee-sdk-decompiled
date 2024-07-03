/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_color_control_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_color_control_cluster_add_attr(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 == 0x4002) {
    uVar2 = 0x11;
    uVar1 = 0x20;
  }
  else if (param_1 < 0x4003) {
    if (param_1 == 7) {
      uVar2 = 0x15;
      uVar1 = 0x21;
    }
    else if (param_1 < 8) {
      if (param_1 == 2) {
        uVar2 = 1;
        uVar1 = 0x21;
      }
      else if (param_1 < 3) {
        if (param_1 == 0) {
          uVar2 = 5;
          uVar1 = 0x20;
        }
        else {
          if (param_1 != 1) goto _L0;
          uVar2 = 0x15;
          uVar1 = 0x20;
        }
      }
      else if (param_1 == 3) {
        uVar2 = 0x15;
        uVar1 = 0x21;
      }
      else {
        if (param_1 != 4) goto _L0;
        uVar2 = 0x15;
        uVar1 = 0x21;
      }
    }
    else if (param_1 == 0x4000) {
      uVar2 = 0x11;
      uVar1 = 0x21;
    }
    else if (param_1 < 0x4001) {
      if (param_1 == 8) {
        uVar2 = 1;
        uVar1 = 0x30;
      }
      else {
        if (param_1 != 0xf) goto _L0;
        uVar2 = 3;
        uVar1 = 0x18;
      }
    }
    else {
      if (param_1 != 0x4001) {
_L0:
        uVar2 = esp_log_timestamp(param_2);
        esp_log_write(1,0x10000,&_LC11,uVar2,0x10000);
        return 0x102;
      }
      uVar2 = 1;
      uVar1 = 0x30;
    }
  }
  else if (param_1 == 0x400a) {
    uVar2 = 1;
    uVar1 = 0x19;
  }
  else if (param_1 < 0x400b) {
    if (param_1 == 0x4005) {
      uVar2 = 1;
      uVar1 = 0x21;
    }
    else if (param_1 < 0x4006) {
      if (param_1 == 0x4003) {
        uVar2 = 0x11;
        uVar1 = 0x20;
      }
      else {
        if (param_1 != 0x4004) goto _L0;
        uVar2 = 0x11;
        uVar1 = 0x21;
      }
    }
    else {
      if (param_1 != 0x4006) goto _L0;
      uVar2 = 1;
      uVar1 = 0x21;
    }
  }
  else if (param_1 == 0x400d) {
    uVar2 = 1;
    uVar1 = 0x21;
  }
  else if (param_1 < 0x400e) {
    if (param_1 == 0x400b) {
      uVar2 = 1;
      uVar1 = 0x21;
    }
    else {
      if (param_1 != 0x400c) goto _L0;
      uVar2 = 1;
      uVar1 = 0x21;
    }
  }
  else {
    if (param_1 != 0x4010) goto _L0;
    uVar2 = 3;
    uVar1 = 0x21;
  }
  uVar2 = esp_zb_internal_cluster_add_attr(0x300,param_1,uVar1,uVar2,0xffff);
  return uVar2;
}

