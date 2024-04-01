/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_ota_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ota_cluster_create(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined1 uStack_25;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined4 auStack_14 [2];
  
  local_30 = 0xffffffff;
  uStack_2c = 0xffffffff;
  uVar1 = esp_zb_zcl_attr_list_create(0x19);
  if (param_1 == (undefined4 *)0x0) {
    auStack_14[0] = 0xffffffff;
    uStack_16 = 0x131b;
    uStack_18 = 0xffbf;
    uStack_1a = 0;
    uStack_20 = 0xffffffff;
    uStack_24 = 0xffffffff;
    uStack_25 = 0;
  }
  else {
    auStack_14[0] = *param_1;
    uStack_16 = *(undefined2 *)(param_1 + 1);
    uStack_18 = *(undefined2 *)((int)param_1 + 6);
    uStack_1a = *(undefined2 *)(param_1 + 2);
    uStack_20 = param_1[3];
    uStack_24 = param_1[4];
    local_30 = param_1[5];
    uStack_2c = param_1[6];
    uStack_25 = *(undefined1 *)(param_1 + 7);
  }
  esp_zb_ota_cluster_add_attr(uVar1,2,auStack_14);
  esp_zb_ota_cluster_add_attr(uVar1,7,&uStack_16);
  esp_zb_ota_cluster_add_attr(uVar1,8,&uStack_18);
  esp_zb_ota_cluster_add_attr(uVar1,0,&local_30);
  esp_zb_ota_cluster_add_attr(uVar1,6,&uStack_25);
  esp_zb_ota_cluster_add_attr(uVar1,9,&uStack_1a);
  esp_zb_ota_cluster_add_attr(uVar1,1,&uStack_20);
  esp_zb_ota_cluster_add_attr(uVar1,4,&uStack_24);
  return uVar1;
}

