/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_start_attr_reporting
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_start_attr_reporting(undefined1 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ezb_zcl_reporting_info_find
                    (*param_1,*(undefined2 *)(param_1 + 2),param_1[4],*(undefined2 *)(param_1 + 8),
                     *(undefined2 *)(param_1 + 6));
  if (iVar1 != 0) {
    ezb_zcl_reporting_start_attr_report();
    uVar2 = esp_zigbee_err_to_esp();
    return uVar2;
  }
  return 0xffffffff;
}

