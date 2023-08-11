/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd.o -> zb_cli_register_reset_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_cli_register_reset_cmd(void)

{
  int iVar1;
  char *pcStack_24;
  char *pcStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  uStack_1c = 0;
  uStack_14 = 0;
  pcStack_24 = "reset";
  pcStack_20 = "ZigBee reset command";
  pcStack_18 = reset_cmd_cb;
  iVar1 = esp_console_cmd_register(&pcStack_24);
  if (iVar1 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  abort();
}

