/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_ec_measurement_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ec_measurement_cluster_create(undefined2 *param_1)

{
  undefined4 uVar1;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 auStack_14 [4];
  
  uStack_18 = 0xffff;
  uStack_16 = 0xffff;
  auStack_14[0] = 0xffff;
  uVar1 = esp_zb_zcl_attr_list_create(0x40a);
  if (param_1 != (undefined2 *)0x0) {
    uStack_18 = *param_1;
    uStack_16 = param_1[1];
    auStack_14[0] = param_1[2];
  }
  esp_zb_ec_measurement_cluster_add_attr(uVar1,0,&uStack_18);
  esp_zb_ec_measurement_cluster_add_attr(uVar1,1,&uStack_16);
  esp_zb_ec_measurement_cluster_add_attr(uVar1,2,auStack_14);
  return uVar1;
}

