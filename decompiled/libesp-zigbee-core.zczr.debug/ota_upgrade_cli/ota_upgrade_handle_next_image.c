/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_handle_next_image
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char ota_upgrade_handle_next_image(int param_1,char *param_2)

{
  char cVar1;
  
  cVar1 = *param_2;
  if (cVar1 == '\0') {
    if (**(short **)(param_1 + 0x1c) == *(short *)(param_2 + 2)) {
      if (**(short **)(param_1 + 0x20) == *(short *)(param_2 + 4)) {
        if ((*(int **)(param_1 + 8) == (int *)0x0) ||
           (**(int **)(param_1 + 8) != *(int *)(param_2 + 8))) {
          if ((*(int **)(param_1 + 0x10) != (int *)0x0) &&
             (**(int **)(param_1 + 0x10) == *(int *)(param_2 + 8))) {
            return -2;
          }
          ota_upgrade_set_upgrade_status_in_progress
                    (0,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0xc));
        }
        else {
          cVar1 = -2;
        }
      }
      else {
        cVar1 = -0x6a;
      }
    }
    else {
      cVar1 = -0x6a;
    }
  }
  else if (cVar1 == '~') {
    ota_upgrade_set_upgrade_status_normal();
  }
  else if (cVar1 == -0x68) {
    ota_upgrade_set_upgrade_status_normal();
  }
  else {
    cVar1 = -2;
  }
  return cVar1;
}

