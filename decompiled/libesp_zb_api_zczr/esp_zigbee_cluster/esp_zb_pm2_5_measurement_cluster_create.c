/*
 * Last changed at upstream commit 37b2129eea9960f95d70bf2e6607337834e2750d
 * https://github.com/espressif/esp-zigbee-sdk/commit/37b2129eea9960f95d70bf2e6607337834e2750d
 * Upstream date: 2023-10-10 17:40:24 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.0(8d71c0ae)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_pm2_5_measurement_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_pm2_5_measurement_cluster_create(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 auStack_14 [2];
  
  uStack_1c = __divsf3(0);
  uStack_18 = uStack_1c;
  auStack_14[0] = uStack_1c;
  uVar1 = esp_zb_zcl_attr_list_create(0x42a);
  if (param_1 != (undefined4 *)0x0) {
    uStack_1c = *param_1;
    uStack_18 = param_1[1];
    auStack_14[0] = param_1[2];
  }
  esp_zb_pm2_5_measurement_cluster_add_attr(uVar1,0,&uStack_1c);
  esp_zb_pm2_5_measurement_cluster_add_attr(uVar1,1,&uStack_18);
  esp_zb_pm2_5_measurement_cluster_add_attr(uVar1,2,auStack_14);
  return uVar1;
}

