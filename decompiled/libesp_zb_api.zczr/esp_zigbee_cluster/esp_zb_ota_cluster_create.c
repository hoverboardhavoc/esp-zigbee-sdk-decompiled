/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_ota_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ota_cluster_create(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined1 uStack_2b;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = 0xffffffff;
  uStack_14 = 0xffffffff;
  uVar1 = esp_zb_zcl_attr_list_create(0x19);
  if (param_1 == (undefined4 *)0x0) {
    uStack_2a = 0x131b;
    uStack_28 = 0xffbf;
    uStack_24 = 0xffffffff;
    uStack_26 = 0;
    uStack_20 = 0xffffffff;
    uStack_1c = 0xffffffff;
    uStack_2b = 0;
  }
  else {
    uStack_24 = *param_1;
    uStack_2a = *(undefined2 *)(param_1 + 1);
    uStack_28 = *(undefined2 *)((int)param_1 + 6);
    uStack_26 = *(undefined2 *)(param_1 + 2);
    uStack_20 = param_1[3];
    uStack_1c = param_1[4];
    memcpy(&uStack_18,param_1 + 5,8);
    uStack_2b = *(undefined1 *)(param_1 + 7);
  }
  esp_zb_ota_cluster_add_attr(uVar1,2,&uStack_24);
  esp_zb_ota_cluster_add_attr(uVar1,7,&uStack_2a);
  esp_zb_ota_cluster_add_attr(uVar1,8,&uStack_28);
  esp_zb_ota_cluster_add_attr(uVar1,0,&uStack_18);
  esp_zb_ota_cluster_add_attr(uVar1,6,&uStack_2b);
  esp_zb_ota_cluster_add_attr(uVar1,9,&uStack_26);
  esp_zb_ota_cluster_add_attr(uVar1,1,&uStack_20);
  esp_zb_ota_cluster_add_attr(uVar1,4,&uStack_1c);
  return uVar1;
}

