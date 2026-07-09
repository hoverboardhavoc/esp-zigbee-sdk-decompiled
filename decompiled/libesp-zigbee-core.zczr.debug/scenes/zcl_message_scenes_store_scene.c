/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> zcl_message_scenes_store_scene
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_message_scenes_store_scene(undefined4 param_1,undefined2 param_2,undefined1 param_3)

{
  uint uVar1;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uVar1 = zcl_packet_to_message(&uStack_34,param_1);
  if (uVar1 == 0) {
    uStack_28._0_3_ = CONCAT12(param_3,param_2);
    uStack_24 = CONCAT31(uStack_24._1_3_,0xfe);
    uStack_2c = param_1;
    zcl_core_action_schedule(0x15,&uStack_34);
    if ((uStack_24 & 0xff) != 0xfe) {
      uVar1 = uStack_24 & 0xff;
    }
  }
  return uVar1;
}

