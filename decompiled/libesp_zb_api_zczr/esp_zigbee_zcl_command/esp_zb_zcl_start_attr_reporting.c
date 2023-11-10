/*
 * Last changed at upstream commit 9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * https://github.com/espressif/esp-zigbee-sdk/commit/9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * Upstream date: 2023-11-10 18:10:39 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.3(ba5a889a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_start_attr_reporting
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_start_attr_reporting(undefined1 *param_1)

{
  zb_zcl_start_attr_reporting_manuf
            (*param_1,*(undefined2 *)(param_1 + 4),param_1[8],*(undefined2 *)(param_1 + 0xe),
             *(undefined2 *)(param_1 + 0xc));
  zb_ret_to_esp_err();
  return;
}

