/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> zcl_message_on_off_set_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_message_on_off_set_attr_value(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 uStack_11;
  
  uStack_11 = param_2;
  iVar1 = on_off_srv_get_attr_desc(0);
  if ((iVar1 == 0) || (iVar2 = zcl_attr_value_is_changed(&uStack_11), iVar2 == 0)) {
    iVar2 = 0x86;
  }
  else {
    iVar2 = on_off_srv_set_attr_value(param_1,0,&uStack_11);
    if (iVar2 == 0) {
      zcl_message_notify_attr_value(param_1,6,1,iVar1);
    }
  }
  return iVar2;
}

