/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_illuminance_meas_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_illuminance_meas_cluster_create(undefined2 *param_1)

{
  undefined4 uVar1;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 auStack_14 [4];
  
  uStack_18 = 0xff;
  uStack_16 = 1;
  auStack_14[0] = 0xfffe;
  uVar1 = esp_zb_zcl_attr_list_create(0x400);
  if (param_1 != (undefined2 *)0x0) {
    uStack_18 = *param_1;
    uStack_16 = param_1[1];
    auStack_14[0] = param_1[2];
  }
  esp_zb_illuminance_meas_cluster_add_attr(uVar1,0,&uStack_18);
  esp_zb_illuminance_meas_cluster_add_attr(uVar1,1,&uStack_16);
  esp_zb_illuminance_meas_cluster_add_attr(uVar1,2,auStack_14);
  return uVar1;
}

