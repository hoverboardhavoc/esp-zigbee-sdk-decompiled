/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_commissioning_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_commissioning_cluster_create(void *param_1)

{
  undefined4 uVar1;
  undefined2 local_50;
  undefined2 uStack_4e;
  undefined2 uStack_4c;
  undefined2 uStack_4a;
  undefined2 uStack_48;
  undefined2 uStack_46;
  undefined4 uStack_44;
  undefined1 uStack_40;
  undefined1 uStack_3f;
  undefined1 uStack_3e;
  undefined1 uStack_3d;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_35;
  undefined1 uStack_34;
  undefined1 uStack_33;
  undefined1 uStack_32;
  undefined1 uStack_31;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined1 uStack_2e;
  undefined1 uStack_2d;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined2 auStack_12 [3];
  
  local_50 = esp_zb_get_short_address();
  uStack_4e = 0xffff;
  uStack_4c = 0xffff;
  uStack_4a = 0xffff;
  uStack_48 = 0xffff;
  uStack_46 = esp_zb_get_pan_id();
  uStack_44 = zb_get_channel_mask();
  uStack_40 = 2;
  uStack_3f = 2;
  uStack_3e = 3;
  uStack_3d = 0;
  uStack_3c = 0;
  uStack_3b = 0;
  uStack_3a = 0;
  uStack_39 = 0;
  uStack_38 = 0;
  uStack_37 = 0;
  uStack_36 = 0;
  uStack_35 = 0;
  uStack_34 = 0;
  uStack_33 = 0;
  uStack_32 = 0;
  uStack_31 = 0;
  uStack_30 = 0;
  uStack_2f = 0;
  uStack_2e = 0;
  uStack_2d = 0;
  uStack_2c = 0;
  uStack_2b = 0;
  uStack_2a = 0;
  uStack_29 = 0;
  uStack_28 = 0;
  uStack_27 = 0;
  uStack_26 = 0;
  uStack_25 = 1;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_13 = 5;
  auStack_12[0] = 0;
  uVar1 = esp_zb_zcl_attr_list_create(0x15);
  if (param_1 != (void *)0x0) {
    memcpy(&local_50,param_1,0x40);
  }
  esp_zb_commissioning_cluster_add_attr(uVar1,0,&local_50);
  esp_zb_commissioning_cluster_add_attr(uVar1,1,&uStack_4e);
  esp_zb_commissioning_cluster_add_attr(uVar1,2,&uStack_46);
  esp_zb_commissioning_cluster_add_attr(uVar1,3,&uStack_44);
  esp_zb_commissioning_cluster_add_attr(uVar1,4,&uStack_40);
  esp_zb_commissioning_cluster_add_attr(uVar1,5,&uStack_3f);
  esp_zb_commissioning_cluster_add_attr(uVar1,6,&uStack_3e);
  esp_zb_commissioning_cluster_add_attr(uVar1,0x10,&uStack_3d);
  esp_zb_commissioning_cluster_add_attr(uVar1,0x12,&uStack_35);
  esp_zb_commissioning_cluster_add_attr(uVar1,0x13,&uStack_25);
  esp_zb_commissioning_cluster_add_attr(uVar1,0x14,&uStack_24);
  esp_zb_commissioning_cluster_add_attr(uVar1,0x15,&uStack_14);
  esp_zb_commissioning_cluster_add_attr(uVar1,0x16,&uStack_13);
  esp_zb_commissioning_cluster_add_attr(uVar1,0x17,auStack_12);
  return uVar1;
}

