/*
 * Last changed at upstream commit 8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * https://github.com/espressif/esp-zigbee-sdk/commit/8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * Upstream date: 2023-11-03 16:33:23 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.2(a51c2f72)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_analog_output_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_analog_output_cluster_create(undefined1 *param_1)

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
  uVar1 = esp_zb_zcl_attr_list_create(0xd);
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
  esp_zb_analog_output_cluster_add_attr(uVar1,0x51,&uStack_1c);
  esp_zb_analog_output_cluster_add_attr(uVar1,0x55,&uStack_18);
  esp_zb_analog_output_cluster_add_attr(uVar1,0x6f,&uStack_14);
  return uVar1;
}

