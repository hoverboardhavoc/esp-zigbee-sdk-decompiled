/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
 * Source: libesp_zb_cli_command -> zb_esp_cli_console_task.o -> zb_cli_console_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_cli_console_init(void)

{
  undefined4 uVar1;
  
  uVar1 = esp_log_timestamp();
  esp_log_write(3,"Zigbee CLI",&_LC5,uVar1,"Zigbee CLI");
  initialize_console();
  esp_console_register_help_command();
  zb_cli_register_command();
  return;
}

