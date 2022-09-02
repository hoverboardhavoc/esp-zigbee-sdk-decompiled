/*
 * Last changed at upstream commit 161b24f200d3999849a30e5fddeac9123c04dbfe
 * https://github.com/espressif/esp-zigbee-sdk/commit/161b24f200d3999849a30e5fddeac9123c04dbfe
 * Upstream date: 2022-09-02 14:39:54 +0800
 * Upstream subject: Components: Separation of the zigbee_core_api header
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_cluster.o -> zcl_get_attr_count
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char zcl_get_attr_count(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  if (param_1 != 0) {
    cVar1 = '\0';
    while (param_1 = *(int *)(param_1 + 0xc), param_1 != 0) {
      cVar1 = cVar1 + '\x01';
    }
    return cVar1;
  }
  uVar2 = esp_log_timestamp();
  esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC1,uVar2,"ESP_ZIGBEE_CLUSTER");
  return '\0';
}

