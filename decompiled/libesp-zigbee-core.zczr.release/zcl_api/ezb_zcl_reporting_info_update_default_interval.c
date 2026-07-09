/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_api.o -> ezb_zcl_reporting_info_update_default_interval
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_reporting_info_update_default_interval
               (int param_1,undefined2 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + 0x28) = param_2;
  *(undefined2 *)(param_1 + 0x2a) = param_3;
  zcl_reporting_info_update();
  return;
}

