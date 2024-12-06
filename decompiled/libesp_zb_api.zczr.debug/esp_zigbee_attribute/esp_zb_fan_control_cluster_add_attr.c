/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_attribute.o -> esp_zb_fan_control_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_fan_control_cluster_add_attr(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 < 2) {
    uVar1 = esp_zb_internal_cluster_add_attr(0x202,param_1,0x30,3,0xffff);
  }
  else {
    uVar1 = esp_log_timestamp(param_2);
    esp_log_write(1,0x10000,&_LC11,uVar1,0x10000);
    uVar1 = 0x102;
  }
  return uVar1;
}

