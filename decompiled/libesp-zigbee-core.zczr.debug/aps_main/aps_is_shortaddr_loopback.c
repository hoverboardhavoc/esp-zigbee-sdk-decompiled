/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_is_shortaddr_loopback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 aps_is_shortaddr_loopback(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_1 < 0xfff8) {
    uVar2 = nwk_get_short_address();
    if (uVar2 == param_1) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else if (param_1 == 0xfffe) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

