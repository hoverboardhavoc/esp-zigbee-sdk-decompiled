/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> zcl_level_affect_on_off_action
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_level_affect_on_off_action(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = on_off_srv_get_attr_desc(0);
  iVar2 = level_srv_get_attr_desc(param_1,2);
  if (iVar1 != 0) {
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (uint)**(byte **)(iVar2 + 8);
    }
    if (uVar3 < param_2) {
      if (**(char **)(iVar1 + 8) == '\0') {
        zcl_message_on_off_set_attr_value(param_1,1);
      }
    }
    else if (**(char **)(iVar1 + 8) != '\0') {
      zcl_message_on_off_set_attr_value(param_1,0);
    }
  }
  return;
}

