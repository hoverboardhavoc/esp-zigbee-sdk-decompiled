/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_set_upgrade_status_in_progress
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ota_upgrade_set_upgrade_status_in_progress
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  **(undefined1 **)(param_1 + 0x18) = 1;
  **(undefined4 **)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 0x2c) = param_3;
  *(undefined4 *)(param_1 + 0x28) = param_4;
  return;
}

