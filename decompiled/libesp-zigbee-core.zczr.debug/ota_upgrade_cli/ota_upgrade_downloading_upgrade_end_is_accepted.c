/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_downloading_upgrade_end_is_accepted
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ota_upgrade_downloading_upgrade_end_is_accepted(int param_1,short *param_2)

{
  if ((**(short **)(param_1 + 0x1c) != *param_2) && (*param_2 != -1)) {
    return 0;
  }
  if ((**(short **)(param_1 + 0x20) != param_2[1]) && (param_2[1] != -1)) {
    return 0;
  }
  if ((*(int *)(param_1 + 0x2c) != *(int *)(param_2 + 2)) && (*(int *)(param_2 + 2) != -1)) {
    return 0;
  }
  if (*(uint *)(param_2 + 6) == 0xffffffff) {
    return 1;
  }
  if (*(uint *)(param_2 + 6) < *(uint *)(param_2 + 4)) {
    return 0;
  }
  return 1;
}

