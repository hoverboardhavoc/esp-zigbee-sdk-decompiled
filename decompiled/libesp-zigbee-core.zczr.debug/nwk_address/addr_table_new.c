/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> addr_table_new
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint addr_table_new(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = bitmap_find_first_zero_bit(*param_1,*(undefined2 *)(param_1 + 2));
  if (uVar1 < *(ushort *)(param_1 + 2)) {
    test_and_set_bitmap(*param_1);
    *(undefined2 *)(param_1[1] + uVar1 * 0x12 + 0xc) = 0xffff;
    *(undefined2 *)(uVar1 * 0x12 + param_1[1] + 10) = 0xffff;
    addr_table_lru_add(param_1,uVar1);
  }
  else {
    uVar1 = 0xffff;
  }
  return uVar1;
}

