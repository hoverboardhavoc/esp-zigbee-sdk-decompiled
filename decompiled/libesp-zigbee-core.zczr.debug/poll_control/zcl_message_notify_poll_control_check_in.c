/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> zcl_message_notify_poll_control_check_in
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_message_notify_poll_control_check_in
               (undefined4 param_1,undefined1 *param_2,undefined2 *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uVar1 = zcl_packet_to_message(&local_30,param_1);
  uVar2 = uVar1;
  if (uVar1 == 0) {
    uStack_24 = CONCAT31(uStack_24._1_3_,0xfe);
    uStack_28 = param_1;
    zcl_core_action_schedule(0x3e,&local_30);
    uVar2 = uStack_24 & 0xff;
    if ((uVar2 == 0xfe) || (uVar1 = uVar2, uVar2 == 0)) {
      uVar2 = uVar1;
      *param_2 = uStack_24._1_1_;
      *param_3 = uStack_24._2_2_;
    }
  }
  return uVar2;
}

