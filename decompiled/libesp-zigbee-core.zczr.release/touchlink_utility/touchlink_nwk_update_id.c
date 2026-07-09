/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_nwk_update_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 touchlink_nwk_update_id(void)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = touchlink_touchlink_info();
  uVar1 = 0;
  if ((uVar2 & 1) == 0) {
    iVar3 = core_globals_get(0);
    uVar1 = *(undefined1 *)(iVar3 + 0x9df);
  }
  return uVar1;
}

