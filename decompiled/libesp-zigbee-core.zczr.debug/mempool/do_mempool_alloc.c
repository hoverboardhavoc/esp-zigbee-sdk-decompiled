/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mempool.o -> do_mempool_alloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int do_mempool_alloc(int param_1)

{
  uint uVar1;
  int iVar2;
  
  do {
    uVar1 = bitmap_find_first_zero_bit(*(undefined4 *)(param_1 + 8),*(undefined2 *)(param_1 + 4));
    if (*(ushort *)(param_1 + 4) <= uVar1) {
      return 0;
    }
    iVar2 = test_and_set_bitmap(uVar1,*(undefined4 *)(param_1 + 8));
  } while (iVar2 != 0);
  return *(int *)(param_1 + 0xc) + uVar1 * *(ushort *)(param_1 + 2);
}

