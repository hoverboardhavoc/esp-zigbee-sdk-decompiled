/*
 * Last changed at upstream commit 62f83e9155a8a668183e90087b29cd6791297d4c
 * https://github.com/espressif/esp-zigbee-sdk/commit/62f83e9155a8a668183e90087b29cd6791297d4c
 * Upstream date: 2023-08-25 15:56:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.1(b4845e06)
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
  esp_log_write(3,"Zigbee CLI",&_LC8,uVar1,"Zigbee CLI");
  initialize_console();
  esp_console_register_help_command();
  zb_cli_register_command();
  return;
}

