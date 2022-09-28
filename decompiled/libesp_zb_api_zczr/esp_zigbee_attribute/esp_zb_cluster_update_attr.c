/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_cluster_update_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_update_attr(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  ushort *puVar2;
  
  if (param_1 == 0) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC1,uVar1,"ESP_ZIGBEE_ATTRIBUTE");
    uVar1 = 0x102;
  }
  else {
    for (puVar2 = *(ushort **)(param_1 + 0xc); puVar2 != (ushort *)0x0;
        puVar2 = *(ushort **)(puVar2 + 6)) {
      if (*puVar2 == param_2) {
        *(undefined4 *)(puVar2 + 2) = param_3;
        return 0;
      }
    }
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_L0,uVar1,"ESP_ZIGBEE_ATTRIBUTE",param_2);
    uVar1 = 0x105;
  }
  return uVar1;
}

