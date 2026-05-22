/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac_filter.o -> mac_filter_remove_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_filter_remove_address(ezb_extaddr_t *extaddr)

{
  mac_filter_entry_t *pmVar1;
  
  if (((extaddr != (ezb_extaddr_t *)0x0) &&
      (pmVar1 = mac_filter_find_entry(extaddr), pmVar1 != (mac_filter_entry_t *)0x0)) &&
     (pmVar1->filtered = false, pmVar1->lqa == '\0')) {
    test_and_clr_bitmap(((int)(pmVar1 + -0x1a34) >> 1) * -0x33333333 & 0xffff,
                        (bitmap_t *)&s_mac_filter_table);
  }
  return;
}

