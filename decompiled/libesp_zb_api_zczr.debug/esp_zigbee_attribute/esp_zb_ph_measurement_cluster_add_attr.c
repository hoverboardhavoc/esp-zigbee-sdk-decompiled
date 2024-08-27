/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_ph_measurement_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ph_measurement_cluster_add_attr(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 5;
  }
  else {
    if (2 < (param_1 - 1U & 0xffff)) {
      uVar1 = esp_log_timestamp(param_2);
      esp_log_write(1,0x10000,&_LC11,uVar1,0x10000);
      return 0x102;
    }
    uVar1 = 1;
  }
  uVar1 = esp_zb_internal_cluster_add_attr(0x409,param_1,0x21,uVar1,0xffff);
  return uVar1;
}

