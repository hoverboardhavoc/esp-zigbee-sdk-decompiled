/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> basic.o -> zcl_message_basic_reset_to_factory_default
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_message_basic_reset_to_factory_default(undefined4 param_1)

{
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  
  local_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  zcl_packet_to_message(&local_20,param_1);
  uStack_14 = CONCAT31(uStack_14._1_3_,0xfe);
  uStack_18 = param_1;
  zcl_core_action_schedule(0xc,&local_20);
  uStack_14 = uStack_14 & 0xff;
  if (uStack_14 == 0xfe) {
    uStack_14 = 0;
  }
  return uStack_14;
}

