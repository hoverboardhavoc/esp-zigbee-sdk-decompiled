/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_cluster.o -> esp_zb_device_temp_config_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_device_temp_config_cluster_create(undefined2 *param_1)

{
  undefined4 uVar1;
  undefined2 auStack_14 [4];
  
  auStack_14[0] = 0x8000;
  uVar1 = esp_zb_zcl_attr_list_create(2);
  if (param_1 != (undefined2 *)0x0) {
    auStack_14[0] = *param_1;
  }
  esp_zb_device_temp_config_cluster_add_attr(uVar1,0,auStack_14);
  return uVar1;
}

