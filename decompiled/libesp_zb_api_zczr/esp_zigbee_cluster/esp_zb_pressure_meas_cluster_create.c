/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_pressure_meas_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_pressure_meas_cluster_create(void *param_1)

{
  undefined4 uVar1;
  undefined4 uStack_18;
  undefined2 auStack_14 [6];
  
  uStack_18 = 0x80018000;
  auStack_14[0] = 0x7fff;
  uVar1 = esp_zb_zcl_attr_list_create(0x403);
  if (param_1 != (void *)0x0) {
    memcpy(&uStack_18,param_1,6);
  }
  esp_zb_pressure_meas_cluster_add_attr(uVar1,0,&uStack_18);
  esp_zb_pressure_meas_cluster_add_attr(uVar1,1,(int)&uStack_18 + 2);
  esp_zb_pressure_meas_cluster_add_attr(uVar1,2,auStack_14);
  return uVar1;
}

