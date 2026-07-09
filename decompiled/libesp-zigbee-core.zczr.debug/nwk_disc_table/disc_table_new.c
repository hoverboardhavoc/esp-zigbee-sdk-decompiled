/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_disc_table.o -> disc_table_new
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * disc_table_new(int param_1)

{
  void *__s;
  uint uVar1;
  
  uVar1 = bitmap_find_first_zero_bit(param_1 + 0x78,6);
  if (uVar1 < 6) {
    test_and_set_bitmap(param_1 + 0x78);
    __s = (void *)(param_1 + uVar1 * 0x14);
    memset(__s,0,0x14);
  }
  else {
    __s = (void *)0x0;
  }
  return __s;
}

