/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_ias_ace_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ias_ace_cluster_create(byte *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  byte abStack_14 [8];
  
  abStack_14[0] = 0xff;
  uVar2 = esp_zb_zcl_attr_list_create(0x501);
  if (param_1 != (byte *)0x0) {
    abStack_14[0] = *param_1;
  }
  pvVar1 = (void *)0x0;
  if ((abStack_14[0] != 0) && (pvVar1 = calloc((uint)abStack_14[0],0xf), pvVar1 == (void *)0x0)) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_L0,uVar3,"ESP_ZIGBEE_CLUSTER");
    abStack_14[0] = 0;
  }
  esp_zb_cluster_add_attr(uVar2,0x501,0xeffe,0x20,1,abStack_14);
  esp_zb_cluster_add_attr(uVar2,0x501,0xefff,abStack_14[0] * '\x0f',0x40,pvVar1);
  return uVar2;
}

