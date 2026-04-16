/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac_filter.o -> test_and_clr_bitmap
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

_Bool test_and_clr_bitmap(uint n,bitmap_t *p)

{
  undefined1 uVar1;
  
  uVar1 = __atomic_fetch_and_1
                    ((int)&s_mac_filter_table.ents[0].extaddr.field_0 + (n >> 3),
                     ~(1 << (n & 7)) & 0xff,5);
  return (_Bool)uVar1;
}

