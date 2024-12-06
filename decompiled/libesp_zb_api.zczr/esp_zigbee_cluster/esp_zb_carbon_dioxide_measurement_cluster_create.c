/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_carbon_dioxide_measurement_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_carbon_dioxide_measurement_cluster_create(void *param_1)

{
  undefined4 uVar1;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 auStack_14 [2];
  
  uStack_1c = __divsf3(0);
  uStack_18 = uStack_1c;
  auStack_14[0] = uStack_1c;
  uVar1 = esp_zb_zcl_attr_list_create(0x40d);
  if (param_1 != (void *)0x0) {
    memcpy(&uStack_1c,param_1,0xc);
  }
  esp_zb_carbon_dioxide_measurement_cluster_add_attr(uVar1,0,&uStack_1c);
  esp_zb_carbon_dioxide_measurement_cluster_add_attr(uVar1,1,&uStack_18);
  esp_zb_carbon_dioxide_measurement_cluster_add_attr(uVar1,2,auStack_14);
  return uVar1;
}

