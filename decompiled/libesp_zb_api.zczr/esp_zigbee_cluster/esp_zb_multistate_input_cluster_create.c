/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_multistate_input_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_multistate_input_cluster_create(void *param_1)

{
  undefined4 uVar1;
  undefined2 uStack_1c;
  undefined1 auStack_1a [2];
  undefined4 uStack_18;
  undefined1 auStack_14 [12];
  
  uStack_1c = 0;
  auStack_1a[0] = 0;
  uStack_18 = 0;
  auStack_14[0] = 0;
  uVar1 = esp_zb_zcl_attr_list_create(0x12);
  if (param_1 != (void *)0x0) {
    memcpy(&uStack_1c,param_1,0xc);
  }
  esp_zb_multistate_input_cluster_add_attr(uVar1,0x4a,&uStack_1c);
  esp_zb_multistate_input_cluster_add_attr(uVar1,0x51,auStack_1a);
  esp_zb_multistate_input_cluster_add_attr(uVar1,0x55,&uStack_18);
  esp_zb_multistate_input_cluster_add_attr(uVar1,0x6f,auStack_14);
  return uVar1;
}

