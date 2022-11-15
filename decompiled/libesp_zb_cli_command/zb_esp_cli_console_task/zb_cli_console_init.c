/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
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

