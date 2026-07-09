/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_touchlink_send_ep_info_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_touchlink_send_ep_info_cmd_req(int param_1)

{
  undefined1 auStack_3c [24];
  undefined1 auStack_24 [8];
  undefined2 uStack_1c;
  undefined1 uStack_1a;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined1 uStack_14;
  
  memset(auStack_3c,0,0x2c);
  if (param_1 != 0) {
    convert_to_ezb_specific_cmd_ctrl(auStack_3c,param_1);
    auStack_3c[0] = 0;
    uStack_1c = ezb_nwk_get_short_address();
    ezb_nwk_get_extended_address(auStack_24);
    uStack_1a = *(undefined1 *)(param_1 + 10);
    uStack_18 = *(undefined2 *)(param_1 + 0xc);
    uStack_16 = *(undefined2 *)(param_1 + 0xe);
    uStack_14 = *(undefined1 *)(param_1 + 0x10);
    ezb_zcl_touchlink_ep_info_cmd_req(auStack_3c);
  }
  return;
}

