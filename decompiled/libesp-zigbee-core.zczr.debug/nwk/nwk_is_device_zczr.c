/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_is_device_zczr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_is_device_zczr(void)

{
  int iVar1;
  
  iVar1 = nwk_is_device_zc();
  if (iVar1 == 0) {
    iVar1 = nwk_is_device_zr();
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}

