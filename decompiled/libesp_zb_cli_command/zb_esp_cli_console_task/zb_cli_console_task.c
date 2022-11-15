/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_console_task.o -> zb_cli_console_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_cli_console_task(void)

{
  int iVar1;
  int iVar2;
  int aiStack_14 [2];
  
  do {
    do {
      iVar1 = linenoise(prompt);
    } while (iVar1 == 0);
    linenoiseHistoryAdd();
    iVar2 = esp_console_run(iVar1,aiStack_14);
    if (iVar2 == 0x105) {
      puts("Unrecognized command");
    }
    else if (iVar2 != 0x102) {
      if ((iVar2 == 0) && (aiStack_14[0] != 0)) {
        esp_err_to_name();
        printf("Command returned non-zero error code: 0x%x (%s)\n");
      }
      else if (iVar2 != 0) {
        esp_err_to_name();
        printf("Internal error: %s\n");
      }
    }
    linenoiseFree(iVar1);
    vTaskDelay(1);
  } while( true );
}

