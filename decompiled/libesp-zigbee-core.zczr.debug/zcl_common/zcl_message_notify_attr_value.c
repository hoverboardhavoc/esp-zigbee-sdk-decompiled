/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_common.o -> zcl_message_notify_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_message_notify_attr_value
               (undefined1 param_1,undefined2 param_2,byte param_3,ushort *param_4)

{
  undefined2 uVar1;
  int iStack_28;
  uint uStack_24;
  uint uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  iStack_28 = (uint)CONCAT21(param_2,param_1) << 8;
  uStack_24 = (uint)param_3;
  if (param_4 != (ushort *)0x0) {
    uStack_20 = (uint)*param_4;
    uStack_1c = (uint)(byte)param_4[1];
    uVar1 = zcl_get_attr_value_size(*(undefined4 *)(param_4 + 4));
    uStack_1c = CONCAT22(uVar1,(undefined2)uStack_1c);
    uStack_18 = *(undefined4 *)(param_4 + 4);
  }
  uStack_14 = CONCAT31(uStack_14._1_3_,0xfe);
  zcl_core_action_schedule(0,&iStack_28);
  return;
}

