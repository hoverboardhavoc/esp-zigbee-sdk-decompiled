/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mempool.o -> mempool_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mempool_free(mempool_type_t type,void *obj)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int extraout_a1;
  uint uVar4;
  mem_pool_t *pmVar5;
  
  if ((type < MEMPOOL_TYPE_MAX_NR) && (obj != (void *)0x0)) {
    pmVar5 = s_mem_pools + type;
    iVar3 = (int)obj - (int)s_mem_pools[type].base_mem;
    uVar4 = (uint)s_mem_pools[type].blk_size;
    uVar2 = iVar3 / (int)uVar4;
    if ((-1 < iVar3) && (iVar3 < (int)(s_mem_pools[type].blk_nr * uVar4))) goto _L0;
    do {
      do {
        uVar2 = __assert_func(0,0,0,0);
        iVar3 = extraout_a1;
_L0:
      } while (iVar3 % (int)uVar4 != 0);
      uVar4 = uVar2 & 7;
      pmVar5 = (mem_pool_t *)pmVar5->blk_busy_map;
      uVar1 = 1 << uVar4 & 0xff;
      uVar2 = __atomic_fetch_and_1(&pmVar5->type + ((uVar2 << 0x10) >> 0x13),~uVar1 & 0xff,5);
    } while ((uVar1 & uVar2) == 0);
    return;
  }
  return;
}

