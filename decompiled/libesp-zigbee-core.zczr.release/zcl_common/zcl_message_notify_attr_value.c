/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_common.o -> zcl_message_notify_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_message_notify_attr_value
               (undefined1 param_1,undefined2 param_2,undefined1 param_3,undefined2 *param_4)

{
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined2 uStack_36;
  undefined1 uStack_34;
  undefined2 uStack_30;
  undefined1 uStack_2c;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined1 uStack_24;
  
  memset(&uStack_38,0,0x18);
  uStack_37 = param_1;
  uStack_36 = param_2;
  uStack_34 = param_3;
  if (param_4 != (undefined2 *)0x0) {
    uStack_30 = *param_4;
    uStack_2c = *(undefined1 *)(param_4 + 1);
    uStack_2a = zcl_get_attr_value_size(*(undefined4 *)(param_4 + 4));
    uStack_28 = *(undefined4 *)(param_4 + 4);
  }
  uStack_24 = 0xfe;
  zcl_core_action_schedule(0,&uStack_38);
  return;
}

