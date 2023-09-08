/*
 * Last changed at upstream commit d50acd5408f73d4459b46a949332bb6e32f97543
 * https://github.com/espressif/esp-zigbee-sdk/commit/d50acd5408f73d4459b46a949332bb6e32f97543
 * Upstream date: 2023-09-08 17:20:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.4(89250ad3)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_pressure_meas_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_pressure_meas_cluster_create(undefined2 *param_1)

{
  undefined4 uVar1;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  
  uStack_18 = 0x8000;
  uStack_16 = 0x8001;
  uStack_14 = 0x7fff;
  uVar1 = esp_zb_zcl_attr_list_create(0x403);
  if (param_1 != (undefined2 *)0x0) {
    uStack_18 = *param_1;
    uStack_16 = param_1[1];
    uStack_14 = param_1[2];
  }
  esp_zb_pressure_meas_cluster_add_attr(uVar1,0,&uStack_18);
  esp_zb_pressure_meas_cluster_add_attr(uVar1,1,&uStack_16);
  esp_zb_pressure_meas_cluster_add_attr(uVar1,2,&uStack_16);
  return uVar1;
}

