/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> zcl_get_attr_count
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char zcl_get_attr_count(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC7,uVar2,"ESP_ZIGBEE_CLUSTER");
    cVar1 = '\0';
  }
  else {
    cVar1 = '\0';
    while (param_1 = *(int *)(param_1 + 0xc), param_1 != 0) {
      cVar1 = cVar1 + '\x01';
    }
  }
  return cVar1;
}

