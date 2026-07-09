/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_zcl_update_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_update_reporting_info(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x102;
  }
  else if (*(int *)(param_1 + 0x40) == 0) {
    uVar1 = 0x102;
  }
  else {
    ezb_zcl_reporting_info_update(*(undefined2 *)(param_1 + 0x18),*(undefined2 *)(param_1 + 0x1a));
    uVar1 = esp_zigbee_err_to_esp();
  }
  return uVar1;
}

