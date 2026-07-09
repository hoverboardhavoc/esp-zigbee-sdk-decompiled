/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mempool.o -> mempool_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mempool_free(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int extraout_a1;
  uint uVar4;
  undefined1 *puVar5;
  
  if ((param_1 < 3) && (param_2 != 0)) {
    iVar2 = param_1 * 0x10;
    puVar5 = s_mem_pools + iVar2;
    param_2 = param_2 - *(int *)(s_mem_pools + iVar2 + 0xc);
    uVar4 = (uint)*(ushort *)(s_mem_pools + iVar2 + 2);
    uVar3 = param_2 / (int)uVar4;
    if ((-1 < param_2) && (param_2 < (int)(*(ushort *)(s_mem_pools + iVar2 + 4) * uVar4))) goto _L0;
    do {
      do {
        uVar3 = __assert_func(0,0,0,0);
        param_2 = extraout_a1;
_L0:
      } while (param_2 % (int)uVar4 != 0);
      uVar4 = uVar3 & 7;
      puVar5 = *(undefined1 **)(puVar5 + 8);
      uVar1 = 1 << uVar4 & 0xff;
      uVar3 = __atomic_fetch_and_1(puVar5 + ((uVar3 << 0x10) >> 0x13),~uVar1 & 0xff,5);
    } while ((uVar1 & uVar3) == 0);
    return;
  }
  return;
}

