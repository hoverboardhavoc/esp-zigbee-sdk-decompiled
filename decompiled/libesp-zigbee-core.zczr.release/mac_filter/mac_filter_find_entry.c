/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_filter.o -> mac_filter_find_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int * mac_filter_find_entry(int *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    uVar1 = bitmap_find_next_bit(s_mac_filter_table,8,uVar1);
    if (7 < uVar1) {
      return (int *)0x0;
    }
    if ((*(int *)(s_mac_filter_table + uVar1 * 10) == *param_1) &&
       (*(int *)(s_mac_filter_table + uVar1 * 10 + 4) == param_1[1])) break;
    uVar1 = uVar1 + 1 & 0xffff;
  }
  return (int *)(s_mac_filter_table + uVar1 * 10);
}

