/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac_filter.o -> mac_filter_new_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

mac_filter_entry_t * mac_filter_new_entry(void)

{
  uint n;
  mac_filter_entry_t *pmVar1;
  
  n = bitmap_find_first_zero_bit(&s_mac_filter_table,8);
  if (n < 8) {
    test_and_set_bitmap(n,(bitmap_t *)&s_mac_filter_table);
    pmVar1 = s_mac_filter_table.ents + n;
    (pmVar1->extaddr).field_0.u8[0] = '\0';
    s_mac_filter_table.ents[n].extaddr.field_0.u8[1] = '\0';
    s_mac_filter_table.ents[n].extaddr.field_0.u8[2] = '\0';
    s_mac_filter_table.ents[n].extaddr.field_0.u8[3] = '\0';
    s_mac_filter_table.ents[n].extaddr.field_0.u8[4] = '\0';
    s_mac_filter_table.ents[n].extaddr.field_0.u8[5] = '\0';
    s_mac_filter_table.ents[n].extaddr.field_0.u8[6] = '\0';
    s_mac_filter_table.ents[n].extaddr.field_0.u8[7] = '\0';
    s_mac_filter_table.ents[n].lqa = '\0';
    s_mac_filter_table.ents[n].filtered = false;
  }
  else {
    pmVar1 = (mac_filter_entry_t *)0x0;
  }
  return pmVar1;
}

