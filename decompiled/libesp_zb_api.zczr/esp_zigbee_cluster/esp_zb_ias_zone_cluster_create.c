/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_ias_zone_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ias_zone_cluster_create(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined2 uStack_36;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  uint uStack_24;
  
  uStack_34 = 0xffffffff;
  uStack_30 = 0xffffffff;
  local_2c = 0;
  uStack_28 = 0;
  uStack_24 = uStack_24 & 0xffff0000;
  uStack_38 = 0;
  uStack_37 = 0;
  uStack_36 = 0;
  uVar1 = esp_zb_zcl_attr_list_create(0x500);
  if (param_1 == (undefined1 *)0x0) {
    uStack_3c = 0;
    uStack_3b = 0;
    uStack_3a = 0;
    uStack_39 = 0xff;
    local_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
  }
  else {
    uStack_3c = *param_1;
    uStack_3b = (undefined1)*(undefined2 *)(param_1 + 2);
    uStack_3a = (undefined1)*(undefined2 *)(param_1 + 4);
    memcpy(&uStack_34,param_1 + 6,8);
    uStack_39 = param_1[0xe];
    memcpy(&local_2c,param_1 + 0x10,0xc);
  }
  esp_zb_ias_zone_cluster_add_attr(uVar1,0,&uStack_3c);
  esp_zb_ias_zone_cluster_add_attr(uVar1,1,&uStack_3b);
  esp_zb_ias_zone_cluster_add_attr(uVar1,2,&uStack_3a);
  esp_zb_ias_zone_cluster_add_attr(uVar1,0x10,&uStack_34);
  esp_zb_ias_zone_cluster_add_attr(uVar1,0x11,&uStack_39);
  esp_zb_ias_zone_cluster_add_attr(uVar1,0xeffe,&local_2c);
  esp_zb_ias_zone_cluster_add_attr(uVar1,0xe000,&uStack_38);
  esp_zb_ias_zone_cluster_add_attr(uVar1,0xe001,&uStack_37);
  esp_zb_ias_zone_cluster_add_attr(uVar1,0xe002,&uStack_36);
  return uVar1;
}

