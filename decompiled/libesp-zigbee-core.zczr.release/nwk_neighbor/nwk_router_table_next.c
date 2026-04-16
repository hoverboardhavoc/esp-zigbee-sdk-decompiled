/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_router_table_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_neighbor_t * nwk_router_table_next(nwk_neighbor_t *nbr)

{
  uint uVar1;
  int iVar2;
  nwk_neighbor_t *pnVar3;
  uint uVar4;
  
  iVar2 = core_globals_get();
  if (nbr == (nwk_neighbor_t *)0x0) {
    uVar4 = 0xffff;
  }
  else {
    uVar4 = (int)nbr - *(int *)(iVar2 + 0xb20) >> 5 & 0xffff;
  }
  uVar1 = (uint)*(ushort *)(iVar2 + 0xb24) - (uint)*(ushort *)(iVar2 + 0xb26) & 0xffff;
  uVar4 = bitmap_find_next_bit(*(undefined4 *)(iVar2 + 0xb1c),uVar1,uVar4 + 1 & 0xffff);
  pnVar3 = (nwk_neighbor_t *)0x0;
  if (uVar4 < uVar1) {
    pnVar3 = (nwk_neighbor_t *)(*(int *)(iVar2 + 0xb20) + uVar4 * 0x20);
  }
  return pnVar3;
}

