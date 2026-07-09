/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_is_op_busy
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mac_is_op_busy(int param_1,uint param_2)

{
  int iVar1;
  
  if (*(byte *)(param_1 + 0x2e) == param_2) {
    iVar1 = 1;
  }
  else {
    iVar1 = mac_is_op_pending();
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}

