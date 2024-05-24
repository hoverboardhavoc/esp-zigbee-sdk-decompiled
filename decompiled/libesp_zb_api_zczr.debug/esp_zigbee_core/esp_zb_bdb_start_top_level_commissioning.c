/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> esp_zb_bdb_start_top_level_commissioning
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_bdb_start_top_level_commissioning(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = bdb_start_top_level_commissioning();
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC25,uVar2,"ESP_ZIGBEE_CORE");
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

