/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
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
  undefined1 auStack_35 [16];
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
  memset(auStack_35,0,0x10);
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
  esp_zb_commissioning_cluster_add_attr(uVar1,0x12,auStack_35);
  esp_zb_commissioning_cluster_add_attr(uVar1,0x13,&uStack_25);
  esp_zb_commissioning_cluster_add_attr(uVar1,0x14,&uStack_24);
  esp_zb_commissioning_cluster_add_attr(uVar1,0x15,&uStack_14);
  esp_zb_commissioning_cluster_add_attr(uVar1,0x16,&uStack_13);
  esp_zb_commissioning_cluster_add_attr(uVar1,0x17,auStack_12);
  return uVar1;
}

