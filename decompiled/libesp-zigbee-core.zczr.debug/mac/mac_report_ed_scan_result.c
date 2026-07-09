/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_report_ed_scan_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_report_ed_scan_result(int param_1,int param_2)

{
  undefined1 uStack_14;
  byte bStack_13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  
  if ((*(code **)(param_1 + 0x38) != (code *)0x0) && (param_2 != 0x7f)) {
    uStack_14 = *(undefined1 *)(param_1 + 0x2c);
    bStack_13 = (byte)((uint)*(undefined4 *)(param_1 + 0x34) >> 0x1b);
    uStack_12 = *(undefined1 *)(param_1 + 0x32);
    uStack_11 = (undefined1)param_2;
    (**(code **)(param_1 + 0x38))(&uStack_14,*(undefined4 *)(param_1 + 0x3c));
  }
  return;
}

