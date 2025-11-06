/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
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
    esp_log(1,"ESP_ZIGBEE_CLUSTER",
            "E (%lu) %s: No sufficient memory for zone table, continue with 0 length.\n",uVar3,
            "ESP_ZIGBEE_CLUSTER");
    abStack_14[0] = 0;
  }
  esp_zb_cluster_add_attr(uVar2,0x501,0xeffe,0x20,1,abStack_14);
  esp_zb_cluster_add_attr(uVar2,0x501,0xefff,abStack_14[0] * '\x0f',0x40,pvVar1);
  return uVar2;
}

