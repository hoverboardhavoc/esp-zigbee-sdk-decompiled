/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_operate_attr_report
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_reporting_operate_attr_report(int param_1,int param_2)

{
  if (param_2 != 0) {
    zcl_reporting_stop();
    *(byte *)(param_2 + 9) = *(byte *)(param_2 + 9) & 0xf0 | (param_1 == 0) * '\x04' + 1U;
    zcl_reporting_start();
    return 0;
  }
  return 2;
}

