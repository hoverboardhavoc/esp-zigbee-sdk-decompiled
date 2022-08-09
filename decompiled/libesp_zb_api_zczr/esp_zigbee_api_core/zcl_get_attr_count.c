/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_core.o -> zcl_get_attr_count
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
  esp_log_write(1,"ESP_ZIGBEE_API_CORE",&_L0,uVar2,"ESP_ZIGBEE_API_CORE");
  return '\0';
}

