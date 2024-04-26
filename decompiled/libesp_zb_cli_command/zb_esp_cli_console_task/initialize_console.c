/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_cli_command -> zb_esp_cli_console_task.o -> initialize_console
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

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
  iVar1 = esp_zb_platform_config_get();
  uStack_38 = *(undefined4 *)(iVar1 + 0x30);
  uStack_34 = *(undefined4 *)(iVar1 + 0x34);
  uStack_30 = *(undefined4 *)(iVar1 + 0x38);
  uStack_2c = *(undefined4 *)(iVar1 + 0x3c);
  uStack_28 = *(undefined4 *)(iVar1 + 0x40);
  uStack_24 = *(undefined4 *)(iVar1 + 0x44);
  uStack_20 = *(undefined4 *)(iVar1 + 0x48);
  uStack_1c = *(undefined4 *)(iVar1 + 0x4c);
  uStack_18 = *(undefined4 *)(iVar1 + 0x50);
  uStack_14 = *(undefined4 *)(iVar1 + 0x54);
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
              ("/builds/thread_zigbee/esp-zboss/components/zboss_cli_command/zb_esp_cli_console_task.c"
               ,0x5c,"initialize_console",0x10000);
  }
  _esp_error_check_failed
            ("/builds/thread_zigbee/esp-zboss/components/zboss_cli_command/zb_esp_cli_console_task.c"
             ,0x66,"initialize_console","esp_console_init(&console_config)");
_L0:
  puts(
      "\nYour terminal application does not support escape sequences.\nLine editing and history features are disabled.\nOn Windows, try using Putty instead."
      );
  linenoiseSetDumbMode(1);
  prompt = &_LC6;
  return;
}

