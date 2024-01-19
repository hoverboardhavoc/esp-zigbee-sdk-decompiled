/*
 * Last changed at upstream commit 0c62d9f04d6c4a739fd0a010d54749e3cd6ae209
 * https://github.com/espressif/esp-zigbee-sdk/commit/0c62d9f04d6c4a739fd0a010d54749e3cd6ae209
 * Upstream date: 2024-01-19 19:10:32 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.9(b7135493)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_ias_zone_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ias_zone_cluster_create(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined2 local_30;
  undefined1 uStack_2e;
  undefined1 uStack_2d;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 uStack_1d;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 auStack_11 [5];
  
  uStack_1c = 0xffffffff;
  uStack_18 = 0xffffffff;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = uStack_24 & 0xffff0000;
  uStack_2d = 0;
  uStack_2e = 0;
  local_30 = 0;
  uVar1 = esp_zb_zcl_attr_list_create(0x500);
  if (param_1 == (undefined1 *)0x0) {
    auStack_11[0] = 0;
    uStack_12 = 0;
    uStack_13 = 0;
    uStack_1d = 0xff;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
  }
  else {
    auStack_11[0] = *param_1;
    uStack_12 = (undefined1)*(undefined2 *)(param_1 + 2);
    uStack_13 = (undefined1)*(undefined2 *)(param_1 + 4);
    uStack_1c = *(undefined4 *)(param_1 + 6);
    uStack_18 = *(undefined4 *)(param_1 + 10);
    uStack_1d = param_1[0xe];
    uStack_2c = *(undefined4 *)(param_1 + 0x10);
    uStack_28 = *(undefined4 *)(param_1 + 0x14);
    uStack_24 = *(uint *)(param_1 + 0x18);
  }
  esp_zb_ias_zone_cluster_add_attr(uVar1,0,auStack_11);
  esp_zb_ias_zone_cluster_add_attr(uVar1,1,&uStack_12);
  esp_zb_ias_zone_cluster_add_attr(uVar1,2,&uStack_13);
  esp_zb_ias_zone_cluster_add_attr(uVar1,0x10,&uStack_1c);
  esp_zb_ias_zone_cluster_add_attr(uVar1,0x11,&uStack_1d);
  esp_zb_ias_zone_cluster_add_attr(uVar1,0xeffe,&uStack_2c);
  esp_zb_ias_zone_cluster_add_attr(uVar1,0xe000,&uStack_2d);
  esp_zb_ias_zone_cluster_add_attr(uVar1,0xe001,&uStack_2e);
  esp_zb_ias_zone_cluster_add_attr(uVar1,0xe002,&local_30);
  return uVar1;
}

