/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> identify.o -> identify_timer_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void identify_timer_handler(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  short asStack_12 [5];
  
  if (param_1 != (undefined1 *)0x0) goto _L22;
  do {
    param_1 = (undefined1 *)__assert_func(0,0,0,0);
_L22:
    iVar3 = identify_srv_get_attr_desc_constprop_0(*param_1);
  } while (iVar3 == 0);
  asStack_12[0] = **(short **)(iVar3 + 8);
  if (asStack_12[0] != 0) {
    asStack_12[0] = asStack_12[0] + -1;
  }
  uVar1 = *param_1;
  iVar3 = ezb_zcl_set_attr_value(uVar1,3,1,0,0,asStack_12,0);
  if (iVar3 == 0) {
    uVar2 = identify_srv_get_attr_desc_constprop_0(uVar1);
    zcl_message_notify_attr_value(uVar1,3,1,uVar2);
  }
  return;
}

