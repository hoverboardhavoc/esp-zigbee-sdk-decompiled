/*
 * Last changed at upstream commit d7e241034cb0adc2116988a320badb285c391de3
 * https://github.com/espressif/esp-zigbee-sdk/commit/d7e241034cb0adc2116988a320badb285c391de3
 * Upstream date: 2024-02-06 17:30:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.1(0cd72dc5)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd.o -> zb_cli_register_reset_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void zb_cli_register_reset_cmd(void)

{
  int iVar1;
  char *pcStack_2c;
  char *pcStack_28;
  undefined4 uStack_24;
  code *pcStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_24 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  pcStack_2c = "reset";
  pcStack_28 = "ZigBee reset command";
  pcStack_20 = reset_cmd_cb;
  iVar1 = esp_console_cmd_register(&pcStack_2c);
  if (iVar1 == 0) {
    return;
  }
  _esp_error_check_failed
            ("/home/xiaqilin/esp/esp-zboss/components/zboss_cli_command/zb_esp_cli_cmd.c",0x10a,
             "zb_cli_register_reset_cmd","esp_console_cmd_register(&reset_cmd)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

