/*
 * Last changed at upstream commit 3a2e620f73272cd71b1255d9566d72d6c662dd1c
 * https://github.com/espressif/esp-zigbee-sdk/commit/3a2e620f73272cd71b1255d9566d72d6c662dd1c
 * Upstream date: 2023-11-24 19:53:05 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.5(909d273b)
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
  _esp_error_check_failed
            ("/home/xieqinan/ESP/esp-zboss/components/zboss_cli_command/zb_esp_cli_cmd.c",0x10a,
             "zb_cli_register_reset_cmd","esp_console_cmd_register(&reset_cmd)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

