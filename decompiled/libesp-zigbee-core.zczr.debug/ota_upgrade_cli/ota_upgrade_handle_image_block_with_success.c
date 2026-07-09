/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_handle_image_block_with_success
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ota_upgrade_handle_image_block_with_success(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (**(short **)(param_1 + 0x1c) == *(short *)(param_2 + 4)) {
    if (**(short **)(param_1 + 0x20) == *(short *)(param_2 + 6)) {
      if (*(int *)(param_1 + 0x2c) == *(int *)(param_2 + 8)) {
        if ((*(uint *)(param_1 + 0x28) != 0) &&
           (*(uint *)(param_1 + 0x28) <= **(int **)(param_1 + 4) + (uint)*(byte *)(param_2 + 0x10)))
        {
          ota_upgrade_set_upgrade_status_complete();
          return 0;
        }
        ota_upgrade_set_upgrade_status_in_progress
                  ((uint)*(byte *)(param_2 + 0x10) + **(int **)(param_1 + 4));
        uVar1 = 0x99;
      }
      else {
        uVar1 = 0xfe;
      }
    }
    else {
      uVar1 = 0xfe;
    }
  }
  else {
    uVar1 = 0xfe;
  }
  return uVar1;
}

