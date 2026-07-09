/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> zcl_message_scenes_view_scene_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_message_scenes_view_scene_resp(undefined4 param_1,undefined1 param_2,int param_3)

{
  uint uVar1;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uVar1 = zcl_packet_to_message(&uStack_3c,param_1);
  if (uVar1 == 0) {
    uStack_30 = CONCAT31(uStack_30._1_3_,param_2);
    uStack_30 = CONCAT22(*(undefined2 *)(param_3 + 2),(undefined2)uStack_30);
    uStack_2c = CONCAT31(uStack_2c._1_3_,*(undefined1 *)(param_3 + 4));
    uStack_2c = CONCAT22(*(undefined2 *)(param_3 + 6),(undefined2)uStack_2c);
    uStack_28 = *(undefined4 *)(param_3 + 0x1c);
    uStack_24 = CONCAT31(uStack_24._1_3_,0xfe);
    uStack_34 = param_1;
    zcl_core_action_schedule(0x13,&uStack_3c);
    if ((uStack_24 & 0xff) != 0xfe) {
      uVar1 = uStack_24 & 0xff;
    }
  }
  return uVar1;
}

