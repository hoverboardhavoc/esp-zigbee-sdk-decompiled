/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_touchlink_send_ep_info_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_touchlink_send_ep_info_cmd_req(int param_1)

{
  undefined2 uVar1;
  uint auStack_3c [8];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  auStack_3c[0] = 0;
  auStack_3c[1] = 0;
  auStack_3c[2] = 0;
  auStack_3c[3] = 0;
  auStack_3c[4] = 0;
  auStack_3c[5] = 0;
  auStack_3c[6] = 0;
  auStack_3c[7] = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 != 0) {
    convert_to_ezb_specific_cmd_ctrl(auStack_3c,param_1);
    auStack_3c[0] = auStack_3c[0] & 0xffffff00;
    uVar1 = ezb_nwk_get_short_address();
    uStack_1c = CONCAT22(uStack_1c._2_2_,uVar1);
    ezb_nwk_get_extended_address(auStack_3c + 6);
    uStack_1c._0_3_ = CONCAT12(*(undefined1 *)(param_1 + 10),(undefined2)uStack_1c);
    uStack_18 = *(undefined4 *)(param_1 + 0xc);
    uStack_14 = CONCAT31(uStack_14._1_3_,*(undefined1 *)(param_1 + 0x10));
    ezb_zcl_touchlink_ep_info_cmd_req(auStack_3c);
  }
  return;
}

