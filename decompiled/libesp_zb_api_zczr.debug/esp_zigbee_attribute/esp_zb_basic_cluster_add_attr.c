/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_basic_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_basic_cluster_add_attr(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 == 0xc) {
    uVar2 = 1;
    uVar1 = 0x42;
  }
  else if (param_1 < 0xd) {
    if (param_1 == 7) {
      uVar2 = 1;
      uVar1 = 0x30;
    }
    else if (param_1 < 8) {
      if (param_1 == 5) {
        uVar2 = 1;
        uVar1 = 0x42;
      }
      else if (param_1 < 6) {
        if (param_1 < 4) {
          uVar2 = 1;
          uVar1 = 0x20;
        }
        else {
          if (param_1 != 4) goto _L0;
          uVar2 = 1;
          uVar1 = 0x42;
        }
      }
      else {
        if (param_1 != 6) {
_L0:
          uVar1 = esp_log_timestamp(param_2);
          esp_log_write(1,0x10000,&_LC11,uVar1,0x10000);
          return 0x102;
        }
        uVar2 = 1;
        uVar1 = 0x42;
      }
    }
    else if (param_1 == 10) {
      uVar2 = 1;
      uVar1 = 0x41;
    }
    else if (param_1 < 0xb) {
      if (param_1 == 8) {
        uVar2 = 1;
        uVar1 = 0x30;
      }
      else {
        if (param_1 != 9) goto _L0;
        uVar2 = 1;
        uVar1 = 0x30;
      }
    }
    else {
      if (param_1 != 0xb) goto _L0;
      uVar2 = 1;
      uVar1 = 0x42;
    }
  }
  else if (param_1 == 0x12) {
    uVar2 = 3;
    uVar1 = 0x10;
  }
  else if (param_1 < 0x13) {
    if (param_1 == 0x10) {
      uVar2 = 3;
      uVar1 = 0x42;
    }
    else if (param_1 < 0x11) {
      if (param_1 == 0xd) {
        uVar2 = 1;
        uVar1 = 0x42;
      }
      else {
        if (param_1 != 0xe) goto _L0;
        uVar2 = 1;
        uVar1 = 0x42;
      }
    }
    else {
      if (param_1 != 0x11) goto _L0;
      uVar2 = 3;
      uVar1 = 0x30;
    }
  }
  else if (param_1 == 0x14) {
    uVar2 = 3;
    uVar1 = 0x18;
  }
  else if (param_1 == 0x4000) {
    uVar2 = 1;
    uVar1 = 0x42;
  }
  else {
    if (param_1 != 0x13) goto _L0;
    uVar2 = 3;
    uVar1 = 0x18;
  }
  uVar1 = esp_zb_internal_cluster_add_attr(0,param_1,uVar1,uVar2,0xffff);
  return uVar1;
}

