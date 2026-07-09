/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_commissioning.o -> zcl_message_group_ids_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_message_group_ids_rsp(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uVar1 = zcl_packet_to_message(&uStack_24,param_1);
  if (uVar1 == 0) {
    uStack_14 = CONCAT31(uStack_14._1_3_,0xfe);
    uStack_1c = param_1;
    uStack_18 = param_2;
    zcl_core_action_schedule(0x52,&uStack_24);
    if ((uStack_14 & 0xff) != 0xfe) {
      uVar1 = uStack_14 & 0xff;
    }
  }
  return uVar1;
}

