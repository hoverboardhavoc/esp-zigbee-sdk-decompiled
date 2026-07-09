/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> zcl_time_get_server_rank
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_time_get_server_rank(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 8;
  uVar1 = param_1 & 1;
  if (param_2 == 0) {
    if (uVar2 != 0) {
      if (uVar1 != 0) {
        return 5;
      }
      goto _L0;
    }
  }
  else {
_L0:
    if (uVar2 == 0) goto _L0;
    if (uVar1 != 0) {
      return 4;
    }
  }
  if (uVar2 != 0) {
    return 3;
  }
_L0:
  if (uVar1 != 0) {
    return 2;
  }
  if ((param_1 & 2) != 0) {
    return 1;
  }
  return 0;
}

