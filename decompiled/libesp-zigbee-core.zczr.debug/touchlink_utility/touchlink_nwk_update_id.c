/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_nwk_update_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 touchlink_nwk_update_id(void)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = touchlink_is_factory_new();
  if (iVar2 == 0) {
    iVar2 = core_globals_get();
    uVar1 = *(undefined1 *)(iVar2 + 0x9df);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

