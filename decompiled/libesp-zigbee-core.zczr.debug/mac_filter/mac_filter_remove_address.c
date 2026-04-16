/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
    test_and_clr_bitmap(((int)((int)&pmVar1[-0x1a33].extaddr.field_0 + 2) >> 1) * -0x33333333 &
                        0xffff,(bitmap_t *)&s_mac_filter_table);
  }
  return;
}

