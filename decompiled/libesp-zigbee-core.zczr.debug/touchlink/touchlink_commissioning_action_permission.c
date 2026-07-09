/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_action_permission
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_commissioning_action_permission(undefined1 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = touchlink_commissioning_get();
  if (*(int *)(iVar1 + 0x50) == 0) {
    uVar2 = 1;
  }
  else {
    iVar1 = touchlink_commissioning_get();
    uVar2 = (**(code **)(iVar1 + 0x50))(param_1,param_2,*(code **)(iVar1 + 0x50));
  }
  return uVar2;
}

