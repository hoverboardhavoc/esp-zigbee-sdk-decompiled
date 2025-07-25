/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_poll_control_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_poll_control_cluster_create(void *param_1)

{
  undefined4 uVar1;
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [2];
  undefined1 auStack_1e [2];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [8];
  
  memcpy(auStack_28,&_L0,0x18);
  uVar1 = esp_zb_zcl_attr_list_create(0x20);
  if (param_1 != (void *)0x0) {
    memcpy(auStack_28,param_1,0x18);
  }
  esp_zb_poll_control_cluster_add_attr(uVar1,0,auStack_28);
  esp_zb_poll_control_cluster_add_attr(uVar1,1,auStack_24);
  esp_zb_poll_control_cluster_add_attr(uVar1,2,auStack_20);
  esp_zb_poll_control_cluster_add_attr(uVar1,3,auStack_1e);
  esp_zb_poll_control_cluster_add_attr(uVar1,4,auStack_1c);
  esp_zb_poll_control_cluster_add_attr(uVar1,5,auStack_18);
  esp_zb_poll_control_cluster_add_attr(uVar1,6,auStack_14);
  return uVar1;
}

