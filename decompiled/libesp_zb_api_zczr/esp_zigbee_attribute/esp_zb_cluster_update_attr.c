/*
 * Last changed at upstream commit dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * https://github.com/espressif/esp-zigbee-sdk/commit/dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * Upstream date: 2022-12-14 19:24:05 +0800
 * Upstream subject: examples:Add ota application example(986c075)
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
        puVar2[3] = (ushort)param_3;
        puVar2[4] = (ushort)((uint)param_3 >> 0x10);
        return 0;
      }
    }
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC17,uVar1,"ESP_ZIGBEE_ATTRIBUTE",param_2);
    uVar1 = 0x105;
  }
  return uVar1;
}

