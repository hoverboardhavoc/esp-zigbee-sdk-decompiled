/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_meter_identification_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_meter_identification_cluster_create(void *param_1)

{
  undefined4 uVar1;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  local_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uVar1 = esp_zb_zcl_attr_list_create(0xb01);
  if (param_1 != (void *)0x0) {
    memcpy(&local_40,param_1,0x2e);
  }
  esp_zb_meter_identification_cluster_add_attr(uVar1,0,&local_40);
  esp_zb_meter_identification_cluster_add_attr(uVar1,1,(int)&uStack_30 + 2);
  esp_zb_meter_identification_cluster_add_attr(uVar1,4,&uStack_2c);
  esp_zb_meter_identification_cluster_add_attr(uVar1,0xc,(int)&uStack_2c + 2);
  esp_zb_meter_identification_cluster_add_attr(uVar1,0xd,(int)&uStack_1c + 3);
  esp_zb_meter_identification_cluster_add_attr(uVar1,0xe,(int)&uStack_18 + 2);
  return uVar1;
}

