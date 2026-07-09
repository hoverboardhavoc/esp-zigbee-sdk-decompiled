/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> identify.o -> identify_timer_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint identify_timer_handler(undefined1 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 extraout_a1;
  short sVar4;
  undefined1 uVar5;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  
  if (param_1 == (undefined1 *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/identify.c",0x89,
                  "identify_timer_handler","timer_ctx");
  }
  else {
    iVar1 = identify_srv_get_attr_desc(*param_1,0);
    if (iVar1 != 0) {
      sVar4 = **(short **)(iVar1 + 8);
      if (sVar4 != 0) {
        sVar4 = sVar4 + -1;
      }
      uVar2 = zcl_message_set_identify_attr_value(*param_1,sVar4);
      return uVar2;
    }
  }
  uVar5 = 8;
  uVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/identify.c",0x8c
                        ,"identify_attr_desc");
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  iVar1 = zcl_packet_to_message(&uStack_44,uVar3);
  if (iVar1 == 0) {
    uStack_38._0_2_ = CONCAT11(uVar5,extraout_a1);
    uStack_34 = CONCAT31(uStack_34._1_3_,0xfe);
    uStack_3c = uVar3;
    zcl_core_action_schedule(0xb,&uStack_44);
    uStack_34 = uStack_34 & 0xff;
    if (uStack_34 == 0xfe) {
      uStack_34 = 0;
    }
  }
  else {
    uStack_34 = 0;
  }
  return uStack_34;
}

