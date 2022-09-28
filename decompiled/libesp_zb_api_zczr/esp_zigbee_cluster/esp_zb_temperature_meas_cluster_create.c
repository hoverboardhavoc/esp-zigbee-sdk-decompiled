/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_temperature_meas_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_temperature_meas_cluster_create(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = esp_zb_zcl_attr_list_create(0x402);
  if (param_1 == 0) {
    esp_zb_temperature_meas_cluster_add_attr(0,&ls16_measure_value_2);
    esp_zb_temperature_meas_cluster_add_attr(uVar1,1,&ls16_min_value_1);
    esp_zb_temperature_meas_cluster_add_attr(uVar1,2,&ls16_max_value_0);
  }
  else {
    esp_zb_temperature_meas_cluster_add_attr(0,param_1);
    esp_zb_temperature_meas_cluster_add_attr(uVar1,1,param_1 + 2);
    esp_zb_temperature_meas_cluster_add_attr(uVar1,2,param_1 + 4);
  }
  return uVar1;
}

