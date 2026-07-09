/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_color_move_to_hue_and_saturation_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_color_move_to_hue_and_saturation_cmd_req(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_30 [24];
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined2 uStack_16;
  
  memset(auStack_30,0,0x20);
  if (param_1 != 0) {
    convert_to_ezb_specific_cmd_ctrl(auStack_30,param_1);
    uStack_18 = *(undefined1 *)(param_1 + 0xb);
    uStack_17 = *(undefined1 *)(param_1 + 0xc);
    uStack_16 = *(undefined2 *)(param_1 + 0xe);
    iVar1 = ezb_zcl_color_control_move_to_hue_and_saturation_cmd_req(auStack_30);
    if (iVar1 == 0) {
      uVar2 = zcl_get_current_tsn();
      return uVar2;
    }
  }
  return 0xff;
}

