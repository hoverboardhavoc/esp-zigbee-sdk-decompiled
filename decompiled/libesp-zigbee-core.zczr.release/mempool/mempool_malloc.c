/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mempool.o -> mempool_malloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mempool_malloc(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (2 < param_1) {
    return 0;
  }
  iVar2 = param_1 * 0x10;
  do {
    uVar3 = bitmap_find_first_zero_bit
                      (*(undefined4 *)(s_mem_pools + iVar2 + 8),
                       *(undefined2 *)(s_mem_pools + iVar2 + 4));
    if (*(ushort *)(s_mem_pools + iVar2 + 4) <= uVar3) {
      return 0;
    }
    uVar1 = 1 << (uVar3 & 7) & 0xff;
    uVar4 = __atomic_fetch_or_1((uVar3 >> 3) + *(int *)(s_mem_pools + iVar2 + 8),uVar1,5);
  } while ((uVar1 & uVar4) != 0);
  return *(int *)(s_mem_pools + iVar2 + 0xc) + *(ushort *)(s_mem_pools + iVar2 + 2) * uVar3;
}

