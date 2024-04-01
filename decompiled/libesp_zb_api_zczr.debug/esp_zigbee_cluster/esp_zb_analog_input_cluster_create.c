/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_analog_input_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_analog_input_cluster_create(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined4 uStack_18;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uVar1 = esp_zb_zcl_attr_list_create(0xc);
  if (param_1 != (undefined1 *)0x0) {
    uStack_1c = *param_1;
    uStack_1b = param_1[1];
    uStack_1a = param_1[2];
    uStack_19 = param_1[3];
    uStack_18 = *(undefined4 *)(param_1 + 4);
    uStack_14 = param_1[8];
    uStack_13 = param_1[9];
    uStack_12 = param_1[10];
    uStack_11 = param_1[0xb];
  }
  esp_zb_analog_input_cluster_add_attr(uVar1,0x51,&uStack_1c);
  esp_zb_analog_input_cluster_add_attr(uVar1,0x55,&uStack_18);
  esp_zb_analog_input_cluster_add_attr(uVar1,0x6f,&uStack_14);
  return uVar1;
}

