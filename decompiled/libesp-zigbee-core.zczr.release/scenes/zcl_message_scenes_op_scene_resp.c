/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> zcl_message_scenes_op_scene_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_message_scenes_op_scene_resp
               (undefined4 param_1,undefined1 param_2,undefined2 param_3,undefined1 param_4)

{
  uint uVar1;
  undefined1 auStack_38 [8];
  undefined4 uStack_30;
  undefined1 uStack_2c;
  undefined2 uStack_2a;
  undefined1 uStack_28;
  byte bStack_24;
  
  memset(auStack_38,0,0x18);
  uVar1 = zcl_packet_to_message(auStack_38,param_1);
  if (uVar1 == 0) {
    bStack_24 = 0xfe;
    uStack_30 = param_1;
    uStack_2c = param_2;
    uStack_2a = param_3;
    uStack_28 = param_4;
    zcl_core_action_schedule(0x12,auStack_38);
    if (bStack_24 != 0xfe) {
      uVar1 = (uint)bStack_24;
    }
  }
  return uVar1;
}

