/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_filter.o -> mac_filter_new_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2 * mac_filter_new_entry(void)

{
  int iVar1;
  uint uVar2;
  undefined2 *puVar3;
  
  uVar2 = bitmap_find_first_zero_bit(s_mac_filter_table,8);
  puVar3 = (undefined2 *)0x0;
  if (uVar2 < 8) {
    __atomic_fetch_or_1(s_mac_filter_table,1 << (uVar2 & 0x1f) & 0xff,5);
    iVar1 = uVar2 * 10;
    puVar3 = (undefined2 *)(s_mac_filter_table + iVar1);
    *puVar3 = 0;
    *(undefined2 *)(s_mac_filter_table + iVar1 + 2) = 0;
    *(undefined2 *)(s_mac_filter_table + iVar1 + 4) = 0;
    *(undefined2 *)(s_mac_filter_table + iVar1 + 6) = 0;
    *(undefined2 *)(s_mac_filter_table + iVar1 + 8) = 0;
  }
  return puVar3;
}

