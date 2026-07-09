/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_initiator_stop_commissioning
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_initiator_stop_commissioning(void)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  if (*(char *)(iVar1 + 0x13ad) == '\x01') {
    iVar1 = core_globals_get();
    *(undefined4 *)(iVar1 + 0x13c0) = 0;
  }
  touchlink_commissioning_set_task(0);
  touchlink_commissioning_set_role(0,0);
  touchlink_disable_timer();
  return 0;
}

