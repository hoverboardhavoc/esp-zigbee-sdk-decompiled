/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_ias_zone_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ias_zone_cluster_create(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined2 uStack_26;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  
  uStack_24 = 0xffffffff;
  uStack_20 = 0xffffffff;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = uStack_14 & 0xffff0000;
  uStack_28 = 0;
  uStack_27 = 0;
  uStack_26 = 0;
  uVar1 = esp_zb_zcl_attr_list_create(0x500);
  if (param_1 == (undefined1 *)0x0) {
    uStack_2c = 0;
    uStack_2b = 0;
    uStack_2a = 0;
    uStack_29 = 0xff;
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_14 = 0;
  }
  else {
    uStack_2c = *param_1;
    uStack_2b = (undefined1)*(undefined2 *)(param_1 + 2);
    uStack_2a = (undefined1)*(undefined2 *)(param_1 + 4);
    memcpy(&uStack_24,param_1 + 6,8);
    uStack_29 = param_1[0xe];
    memcpy(&uStack_1c,param_1 + 0x10,0xc);
  }
  esp_zb_ias_zone_cluster_add_attr(uVar1,0,&uStack_2c);
  esp_zb_ias_zone_cluster_add_attr(uVar1,1,&uStack_2b);
  esp_zb_ias_zone_cluster_add_attr(uVar1,2,&uStack_2a);
  esp_zb_ias_zone_cluster_add_attr(uVar1,0x10,&uStack_24);
  esp_zb_ias_zone_cluster_add_attr(uVar1,0x11,&uStack_29);
  esp_zb_ias_zone_cluster_add_attr(uVar1,0xeffe,&uStack_1c);
  esp_zb_ias_zone_cluster_add_attr(uVar1,0xe000,&uStack_28);
  esp_zb_ias_zone_cluster_add_attr(uVar1,0xe001,&uStack_27);
  esp_zb_ias_zone_cluster_add_attr(uVar1,0xe002,&uStack_26);
  return uVar1;
}

