/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_analog_value_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_analog_value_cluster_create(void *param_1)

{
  undefined4 uVar1;
  undefined1 auStack_1c [4];
  undefined4 uStack_18;
  undefined1 auStack_14 [12];
  
  auStack_1c[0] = 0;
  uStack_18 = 0;
  auStack_14[0] = 0;
  uVar1 = esp_zb_zcl_attr_list_create(0xe);
  if (param_1 != (void *)0x0) {
    memcpy(auStack_1c,param_1,0xc);
  }
  esp_zb_analog_value_cluster_add_attr(uVar1,0x51,auStack_1c);
  esp_zb_analog_value_cluster_add_attr(uVar1,0x55,&uStack_18);
  esp_zb_analog_value_cluster_add_attr(uVar1,0x6f,auStack_14);
  return uVar1;
}

