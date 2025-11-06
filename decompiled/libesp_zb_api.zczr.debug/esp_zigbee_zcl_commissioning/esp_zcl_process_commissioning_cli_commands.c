/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_process_commissioning_cli_commands
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zcl_process_commissioning_cli_commands(int param_1)

{
  undefined4 uVar1;
  
  if (*(byte *)(param_1 + 0x1c) < 4) {
    uVar1 = esp_zcl_commissioning_cli_process_response();
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log(2,"ESP_ZIGBEE_ZCL_COMMISSIONING","W (%lu) %s: Unsupported commissioning command(0x%x)\n"
            ,uVar1,"ESP_ZIGBEE_ZCL_COMMISSIONING",*(undefined1 *)(param_1 + 0x1c));
    uVar1 = 0;
  }
  return uVar1;
}

