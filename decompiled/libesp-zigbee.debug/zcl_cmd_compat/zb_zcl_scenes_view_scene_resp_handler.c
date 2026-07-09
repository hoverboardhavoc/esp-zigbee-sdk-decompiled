/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_scenes_view_scene_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_scenes_view_scene_resp_handler(int param_1,code *param_2)

{
  undefined1 uVar1;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  convert_to_esp_zb_zcl_cmd_info(&uStack_3c,*(undefined4 *)(param_1 + 8));
  uStack_3c = CONCAT31(uStack_3c._1_3_,*(undefined1 *)(param_1 + 0xc));
  uStack_1c = CONCAT13(uStack_1c._3_1_,*(undefined3 *)(param_1 + 0xe));
  uStack_18 = CONCAT22(uStack_18._2_2_,*(undefined2 *)(param_1 + 0x12));
  uStack_14 = *(undefined4 *)(param_1 + 0x14);
  if (param_2 != (code *)0x0) {
    (*param_2)(0x13,&uStack_3c);
    uVar1 = esp_err_to_zcl_status();
    *(undefined1 *)(param_1 + 0x18) = uVar1;
  }
  return;
}

