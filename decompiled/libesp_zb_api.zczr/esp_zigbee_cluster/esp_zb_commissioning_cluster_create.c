/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_commissioning_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_commissioning_cluster_create(void *param_1)

{
  undefined4 uVar1;
  undefined2 local_50;
  undefined1 auStack_4e [8];
  undefined2 uStack_46;
  undefined4 uStack_44;
  undefined1 uStack_40;
  undefined1 uStack_3f;
  undefined1 uStack_3e;
  undefined1 auStack_3d [8];
  undefined1 auStack_35 [16];
  undefined1 uStack_25;
  undefined1 auStack_24 [16];
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 auStack_12 [6];
  
  local_50 = esp_zb_get_short_address();
  memcpy(auStack_4e,&_L0,8);
  uStack_46 = esp_zb_get_pan_id();
  uStack_44 = zb_get_channel_mask();
  memcpy(&uStack_40,&_L0,0x30);
  uVar1 = esp_zb_zcl_attr_list_create(0x15);
  if (param_1 != (void *)0x0) {
    memcpy(&local_50,param_1,0x40);
  }
  esp_zb_commissioning_cluster_add_attr(uVar1,0,&local_50);
  esp_zb_commissioning_cluster_add_attr(uVar1,1,auStack_4e);
  esp_zb_commissioning_cluster_add_attr(uVar1,2,&uStack_46);
  esp_zb_commissioning_cluster_add_attr(uVar1,3,&uStack_44);
  esp_zb_commissioning_cluster_add_attr(uVar1,4,&uStack_40);
  esp_zb_commissioning_cluster_add_attr(uVar1,5,&uStack_3f);
  esp_zb_commissioning_cluster_add_attr(uVar1,6,&uStack_3e);
  esp_zb_commissioning_cluster_add_attr(uVar1,0x10,auStack_3d);
  esp_zb_commissioning_cluster_add_attr(uVar1,0x12,auStack_35);
  esp_zb_commissioning_cluster_add_attr(uVar1,0x13,&uStack_25);
  esp_zb_commissioning_cluster_add_attr(uVar1,0x14,auStack_24);
  esp_zb_commissioning_cluster_add_attr(uVar1,0x15,&uStack_14);
  esp_zb_commissioning_cluster_add_attr(uVar1,0x16,&uStack_13);
  esp_zb_commissioning_cluster_add_attr(uVar1,0x17,auStack_12);
  return uVar1;
}

