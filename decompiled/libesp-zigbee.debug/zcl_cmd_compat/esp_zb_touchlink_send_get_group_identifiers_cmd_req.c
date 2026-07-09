/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_touchlink_send_get_group_identifiers_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_touchlink_send_get_group_identifiers_cmd_req(int param_1)

{
  uint auStack_2c [6];
  undefined4 uStack_14;
  
  auStack_2c[0] = 0;
  auStack_2c[1] = 0;
  auStack_2c[2] = 0;
  auStack_2c[3] = 0;
  auStack_2c[4] = 0;
  auStack_2c[5] = 0;
  uStack_14 = 0;
  if (param_1 != 0) {
    convert_to_ezb_specific_cmd_ctrl(auStack_2c,param_1);
    auStack_2c[0] = auStack_2c[0] & 0xffffff00;
    uStack_14 = CONCAT31(uStack_14._1_3_,*(undefined1 *)(param_1 + 10));
    ezb_zcl_touchlink_get_group_ids_cmd_req(auStack_2c);
  }
  return;
}

