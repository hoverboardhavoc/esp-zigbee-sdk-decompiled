/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_filter.o -> test_and_set_bitmap
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool test_and_set_bitmap(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 1 << (param_1 & 7) & 0xff;
  uVar2 = __atomic_fetch_or_1((param_1 >> 3) + param_2,uVar1,5);
  return (uVar2 & uVar1) != 0;
}

