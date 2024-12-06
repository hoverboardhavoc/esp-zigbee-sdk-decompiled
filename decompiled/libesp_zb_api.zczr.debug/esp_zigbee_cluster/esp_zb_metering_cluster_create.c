/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_cluster.o -> esp_zb_metering_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_metering_cluster_create(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0x1b;
  uVar1 = esp_zb_zcl_attr_list_create(0x702);
  if (param_1 != (undefined4 *)0x0) {
    uStack_1c = *param_1;
    uStack_18 = param_1[1];
    uStack_14 = *(undefined2 *)(param_1 + 2);
  }
  esp_zb_cluster_add_attr(uVar1,0x702,0,0x25,1,&uStack_1c);
  esp_zb_cluster_add_attr(uVar1,0x702,0x200,0x18,1,(int)&uStack_18 + 2);
  esp_zb_cluster_add_attr(uVar1,0x702,0x300,0x30,1,(int)&uStack_18 + 3);
  esp_zb_cluster_add_attr(uVar1,0x702,0x303,0x18,1,&uStack_14);
  esp_zb_cluster_add_attr(uVar1,0x702,0x306,0x18,1,(int)&uStack_14 + 1);
  return uVar1;
}

