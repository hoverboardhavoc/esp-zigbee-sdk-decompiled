/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> zcl_message_color_mode_change
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_message_color_mode_change
               (undefined4 param_1,undefined1 param_2,undefined1 param_3,undefined2 *param_4)

{
  uint uVar1;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uVar1 = zcl_packet_to_message(&uStack_38,param_1);
  if (uVar1 == 0) {
    uStack_2c._0_2_ = CONCAT11(param_2,param_3);
    uStack_28 = CONCAT31(uStack_28._1_3_,0xfe);
    uStack_30 = param_1;
    zcl_core_action_schedule(0x1c,&uStack_38);
    if ((char)uStack_28 == '\0') {
      *param_4 = uStack_28._2_2_;
      param_4[1] = (undefined2)uStack_24;
      param_4[2] = uStack_24._2_2_;
    }
    uVar1 = uStack_28 & 0xff;
  }
  return uVar1;
}

