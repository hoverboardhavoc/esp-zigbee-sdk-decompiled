/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac_filter.o -> mac_filter_find_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

mac_filter_entry_t * mac_filter_find_entry(ezb_extaddr_t *extaddr)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    uVar1 = bitmap_find_next_bit(&s_mac_filter_table,8,uVar1);
    if (7 < uVar1) {
      return (mac_filter_entry_t *)0x0;
    }
    if ((*(int *)&s_mac_filter_table.ents[uVar1].extaddr.field_0 == *(int *)&extaddr->field_0) &&
       (*(int *)((int)&s_mac_filter_table.ents[uVar1].extaddr.field_0 + 4) ==
        *(int *)((int)&extaddr->field_0 + 4))) break;
    uVar1 = uVar1 + 1 & 0xffff;
  }
  return s_mac_filter_table.ents + uVar1;
}

