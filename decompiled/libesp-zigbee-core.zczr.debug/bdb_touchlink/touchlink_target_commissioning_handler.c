/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_target_commissioning_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_target_commissioning_handler(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xd4c) = 4;
  }
  else if ((param_1 - 4U & 0xff) < 3) {
    if (param_2 == 0) {
      iVar1 = core_globals_get();
      *(undefined1 *)(iVar1 + 0xd4c) = 0;
      zdo_dev_set_joined(1);
    }
    else {
      iVar1 = core_globals_get();
      *(undefined1 *)(iVar1 + 0xd4c) = 3;
      zdo_dev_set_joined(0);
    }
  }
  else {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xd4c) = 4;
  }
  touchlink_target_stop_commissioning();
  bdb_comm_finish_touchlink_target();
  return;
}

