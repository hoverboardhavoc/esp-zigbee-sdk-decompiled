/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_zigbee_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint touchlink_zigbee_info(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = nwk_is_device_zc();
  if (iVar2 == 0) {
    iVar2 = nwk_is_device_zr();
    uVar1 = 1;
    if (iVar2 != 0) goto _L0;
    iVar2 = nwk_is_device_zed();
    uVar1 = 2;
    if (iVar2 != 0) goto _L0;
    __assert_func(0,0,0);
  }
  uVar1 = 0;
_L0:
  iVar2 = core_globals_get();
  return uVar1 | (uint)*(byte *)(iVar2 + 0x9ee) << 2;
}

