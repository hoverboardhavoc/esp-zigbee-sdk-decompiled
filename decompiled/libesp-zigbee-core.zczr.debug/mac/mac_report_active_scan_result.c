/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_report_active_scan_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_report_active_scan_result(int param_1,int param_2)

{
  int iVar1;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (*(code **)(param_1 + 0x38) != (code *)0x0) {
    if (param_2 == 0) {
      (**(code **)(param_1 + 0x38))(0,*(undefined4 *)(param_1 + 0x3c));
    }
    else {
      uStack_2c = 0;
      uStack_28 = 0;
      uStack_24 = 0;
      uStack_20 = 0;
      uStack_1c = 0;
      uStack_18 = 0;
      uStack_14 = 0;
      iVar1 = mac_convert_beacon_to_active_scan_result(&uStack_2c);
      if (iVar1 == 0) {
        (**(code **)(param_1 + 0x38))
                  (&uStack_2c,*(undefined4 *)(param_1 + 0x3c),*(code **)(param_1 + 0x38));
      }
    }
  }
  return;
}

