/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
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
    vTaskDelay(1);
  } while( true );
}

