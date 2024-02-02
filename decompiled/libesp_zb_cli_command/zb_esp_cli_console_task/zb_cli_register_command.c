/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
 * Source: libesp_zb_cli_command -> zb_esp_cli_console_task.o -> zb_cli_register_command
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_cli_register_command(void)

{
  zb_cli_register_bdb_cmd();
  zb_cli_register_tlk_cmd();
  zb_cli_register_zdo_cmd();
  zb_cli_register_zcl_cmd();
  zb_cli_register_reset_cmd();
  return;
}

