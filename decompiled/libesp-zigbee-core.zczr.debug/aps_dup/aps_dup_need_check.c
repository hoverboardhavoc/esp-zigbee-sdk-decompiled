/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_dup.o -> aps_dup_need_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 aps_dup_need_check(int param_1)

{
  char cVar1;
  
  if ((*(byte *)(param_1 + 0xc) & 3) == 2) {
    return 0;
  }
  cVar1 = *(char *)(param_1 + 0xe);
  if (cVar1 == '\x0e') {
    return 0;
  }
  if (cVar1 == '\x12') {
    return 0;
  }
  if (cVar1 != '\x11') {
    return 1;
  }
  return 0;
}

