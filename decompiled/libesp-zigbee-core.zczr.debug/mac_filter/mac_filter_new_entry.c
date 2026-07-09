/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_filter.o -> mac_filter_new_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * mac_filter_new_entry(void)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  uVar1 = bitmap_find_first_zero_bit(s_mac_filter_table,8);
  if (uVar1 < 8) {
    test_and_set_bitmap(s_mac_filter_table);
    iVar2 = uVar1 * 10;
    puVar3 = s_mac_filter_table + iVar2;
    *puVar3 = 0;
    s_mac_filter_table[iVar2 + 1] = 0;
    s_mac_filter_table[iVar2 + 2] = 0;
    s_mac_filter_table[iVar2 + 3] = 0;
    s_mac_filter_table[iVar2 + 4] = 0;
    s_mac_filter_table[iVar2 + 5] = 0;
    s_mac_filter_table[iVar2 + 6] = 0;
    s_mac_filter_table[iVar2 + 7] = 0;
    s_mac_filter_table[iVar2 + 8] = 0;
    s_mac_filter_table[iVar2 + 9] = 0;
  }
  else {
    puVar3 = (undefined1 *)0x0;
  }
  return puVar3;
}

