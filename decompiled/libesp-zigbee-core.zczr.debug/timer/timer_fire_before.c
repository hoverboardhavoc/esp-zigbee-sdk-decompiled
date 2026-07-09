/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> timer.o -> timer_fire_before
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint timer_fire_before(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0xc) - param_3;
  if (-1 < (int)(*(int *)(param_2 + 0xc) - param_3 ^ uVar1)) {
    uVar1 = *(int *)(param_1 + 0xc) - *(int *)(param_2 + 0xc);
  }
  return uVar1 >> 0x1f;
}

