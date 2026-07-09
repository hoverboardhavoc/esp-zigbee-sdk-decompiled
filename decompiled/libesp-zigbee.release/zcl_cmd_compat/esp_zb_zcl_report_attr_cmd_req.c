/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_report_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_report_attr_cmd_req(int param_1)

{
  undefined4 uVar1;
  undefined1 auStack_30 [28];
  undefined2 uStack_14;
  
  memset(auStack_30,0,0x20);
  uVar1 = 0x102;
  if (param_1 != 0) {
    convert_to_ezb_general_cmd_ctrl(auStack_30,param_1);
    uStack_14 = *(undefined2 *)(param_1 + 0x12);
    ezb_zcl_report_attr_cmd_req(auStack_30);
    uVar1 = esp_zigbee_err_to_esp();
  }
  return uVar1;
}

