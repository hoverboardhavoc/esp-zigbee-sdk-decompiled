/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_ias_ace_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ias_ace_cluster_create(byte *param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 uVar3;
  byte abStack_14 [4];
  
  abStack_14[0] = 0xff;
  uVar1 = esp_zb_zcl_attr_list_create(0x501);
  if (param_1 != (byte *)0x0) {
    abStack_14[0] = *param_1;
  }
  if (abStack_14[0] != 0) {
    pvVar2 = calloc((uint)abStack_14[0],0xf);
    if (pvVar2 != (void *)0x0) goto _L0;
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC14,uVar3,"ESP_ZIGBEE_CLUSTER");
    abStack_14[0] = 0;
  }
  pvVar2 = (void *)0x0;
_L0:
  esp_zb_cluster_add_attr(uVar1,0x501,0xeffe,0x20,1,abStack_14);
  esp_zb_cluster_add_attr(uVar1,0x501,0xefff,abStack_14[0] * '\x0f',0x40,pvVar2);
  return uVar1;
}

