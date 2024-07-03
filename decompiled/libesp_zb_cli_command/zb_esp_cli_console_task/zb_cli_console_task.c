/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
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
      if (iVar2 == 0) {
        if (aiStack_14[0] != 0) {
          esp_err_to_name();
          printf("Command returned non-zero error code: 0x%x (%s)\n");
        }
      }
      else {
        esp_err_to_name();
        printf("Internal error: %s\n");
      }
    }
    linenoiseFree(iVar1);
    vTaskDelay(10);
  } while( true );
}

