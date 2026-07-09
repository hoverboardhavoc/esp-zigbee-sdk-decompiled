/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> identify.o -> zcl_message_set_identify_attr_value.isra.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_message_set_identify_attr_value_isra_0(undefined1 param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 auStack_12 [5];
  
  auStack_12[0] = param_2;
  iVar1 = ezb_zcl_set_attr_value(param_1,3,1,0,0,auStack_12,0);
  if (iVar1 == 0) {
    uVar2 = identify_srv_get_attr_desc_constprop_0(param_1);
    zcl_message_notify_attr_value(param_1,3,1,uVar2);
  }
  return;
}

