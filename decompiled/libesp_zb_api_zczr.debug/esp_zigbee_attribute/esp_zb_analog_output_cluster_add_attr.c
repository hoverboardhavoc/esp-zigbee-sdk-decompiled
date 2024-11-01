/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_analog_output_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_analog_output_cluster_add_attr(uint param_1,undefined4 param_2)

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
    else if (param_1 < 0x52) {
      if (param_1 == 0x1c) {
        uVar2 = 1;
        uVar1 = 0x42;
      }
      else {
        if (param_1 < 0x1c) goto _L0;
        if (param_1 == 0x41) {
          uVar2 = 1;
          uVar1 = 0x39;
        }
        else {
          if (param_1 != 0x45) goto _L0;
          uVar2 = 1;
          uVar1 = 0x39;
        }
      }
    }
    else {
      if (param_1 != 0x55) goto _L0;
      uVar2 = 7;
      uVar1 = 0x39;
    }
  }
  else if (param_1 == 0x75) {
    uVar2 = 1;
    uVar1 = 0x31;
  }
  else if (param_1 < 0x76) {
    if (param_1 == 0x6f) {
      uVar2 = 5;
      uVar1 = 0x18;
    }
    else {
      if (0x6f < param_1) {
_L0:
        uVar1 = esp_log_timestamp(param_2);
        esp_log_write(1,0x10000,&_LC11,uVar1,0x10000);
        return 0x102;
      }
      if (param_1 == 0x68) {
        uVar2 = 1;
        uVar1 = 0x39;
      }
      else {
        if (param_1 != 0x6a) goto _L0;
        uVar2 = 1;
        uVar1 = 0x39;
      }
    }
  }
  else {
    if (param_1 != 0x100) goto _L0;
    uVar2 = 1;
    uVar1 = 0x23;
  }
  uVar1 = esp_zb_internal_cluster_add_attr(0xd,param_1,uVar1,uVar2,0xffff);
  return uVar1;
}

