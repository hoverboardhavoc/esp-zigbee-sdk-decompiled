/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac_filter.o -> mac_filter_new_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

mac_filter_entry_t * mac_filter_new_entry(void)

{
  uint uVar1;
  mac_filter_entry_t *pmVar2;
  
  uVar1 = bitmap_find_first_zero_bit(&s_mac_filter_table,8);
  pmVar2 = (mac_filter_entry_t *)0x0;
  if (uVar1 < 8) {
    __atomic_fetch_or_1(&s_mac_filter_table,1 << (uVar1 & 0x1f) & 0xff,5);
    pmVar2 = s_mac_filter_table.ents + uVar1;
    *(undefined2 *)&(pmVar2->extaddr).field_0 = 0;
    *(undefined2 *)((int)&s_mac_filter_table.ents[uVar1].extaddr.field_0 + 2) = 0;
    *(undefined2 *)((int)&s_mac_filter_table.ents[uVar1].extaddr.field_0 + 4) = 0;
    *(undefined2 *)((int)&s_mac_filter_table.ents[uVar1].extaddr.field_0 + 6) = 0;
    s_mac_filter_table.ents[uVar1].lqa = '\0';
    s_mac_filter_table.ents[uVar1].filtered = false;
  }
  return pmVar2;
}

