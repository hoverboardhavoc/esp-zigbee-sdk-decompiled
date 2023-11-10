/*
 * Last changed at upstream commit 9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * https://github.com/espressif/esp-zigbee-sdk/commit/9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * Upstream date: 2023-11-10 18:10:39 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.3(ba5a889a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_reset_all_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_reset_all_reporting_info(void)

{
  zb_zcl_init_reporting_info();
  return;
}

