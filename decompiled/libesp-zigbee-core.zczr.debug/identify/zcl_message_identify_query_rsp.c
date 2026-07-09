/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> identify.o -> zcl_message_identify_query_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_message_identify_query_rsp(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
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
  iVar1 = zcl_packet_to_message(&uStack_24,param_1);
  if (iVar1 == 0) {
    uStack_18 = CONCAT22(uStack_18._2_2_,param_2);
    uStack_14 = CONCAT31(uStack_14._1_3_,0xfe);
    uStack_1c = param_1;
    zcl_core_action_schedule(10,&uStack_24);
    uStack_14 = uStack_14 & 0xff;
    if (uStack_14 == 0xfe) {
      uStack_14 = 0;
    }
  }
  else {
    uStack_14 = 0;
  }
  return uStack_14;
}

