/*
 * Last changed at upstream commit d04ab25a7353bae74042267d24c5fef5f02d0726
 * https://github.com/espressif/esp-zigbee-sdk/commit/d04ab25a7353bae74042267d24c5fef5f02d0726
 * Upstream date: 2023-08-08 16:02:31 +0800
 * Upstream subject: esp-zigbee-sdk: add touchlink example
 * Source: libesp_zb_cli_command -> zb_esp_cli_console_task.o -> initialize_console
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initialize_console(void)

{
  int iVar1;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = __getreent();
  fflush(*(FILE **)(iVar1 + 8));
  iVar1 = __getreent();
  iVar1 = fileno(*(FILE **)(iVar1 + 8));
  fsync(iVar1);
  uStack_38 = __esp_error_check_failed;
  uStack_34 = _linenoiseSetDumbMode;
  uStack_30 = _zb_cli_register_bdb_cmd;
  uStack_2c = _zb_cli_register_zdo_cmd;
  uStack_28 = _zb_cli_register_zcl_cmd;
  uStack_24 = _zb_cli_register_reset_cmd;
  uStack_20 = _esp_log_timestamp;
  uStack_1c = _esp_log_write;
  uStack_18 = _esp_console_register_help_command;
  uStack_14 = _linenoiseFree;
  iVar1 = zb_esp_uart_init(&uStack_38,0,1);
  if (iVar1 == 0) {
    iStack_40 = 0;
    uStack_3c = 0;
    uStack_48 = 0x100;
    uStack_44 = 100;
    iStack_40 = atoi("36");
    iVar1 = esp_console_init(&uStack_48);
    if (iVar1 == 0) {
      linenoiseSetMultiLine(1);
      linenoiseSetCompletionCallback(&esp_console_get_completion);
      linenoiseSetHintsCallback(&esp_console_get_hint);
      linenoiseHistorySetMaxLen(10);
      puts(
          "\nType \'help\' to get the list of commands.\nUse UP/DOWN arrows to navigate through command history.\nPress TAB when typing command name to auto-complete."
          );
      iVar1 = linenoiseProbe();
      if (iVar1 == 0) {
        return;
      }
      goto _L0;
    }
  }
  else {
    _esp_error_check_failed
              ("/home/xiaqilin/esp/esp-zboss/components/zboss_cli_command/zb_esp_cli_console_task.c"
               ,0x5c,"initialize_console",0x10000);
  }
  _esp_error_check_failed
            ("/home/xiaqilin/esp/esp-zboss/components/zboss_cli_command/zb_esp_cli_console_task.c",
             0x66,"initialize_console","esp_console_init(&console_config)");
_L0:
  puts(
      "\nYour terminal application does not support escape sequences.\nLine editing and history features are disabled.\nOn Windows, try using Putty instead."
      );
  linenoiseSetDumbMode(1);
  prompt = &_LC6;
  return;
}

