/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_table_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_route_t * nwk_route_table_next(nwk_route_t *route)

{
  int iVar1;
  nwk_route_t *pnVar2;
  uint uVar3;
  
  iVar1 = core_globals_get();
  if (route == (nwk_route_t *)0x0) {
    uVar3 = 0xffff;
  }
  else {
    uVar3 = (int)route - *(int *)(iVar1 + 0xcbc) >> 4 & 0xffff;
  }
  uVar3 = bitmap_find_next_bit
                    (*(undefined4 *)(iVar1 + 0xcc0),*(undefined2 *)(iVar1 + 0xcc4),
                     uVar3 + 1 & 0xffff);
  if (uVar3 < *(ushort *)(iVar1 + 0xcc4)) {
    pnVar2 = (nwk_route_t *)(uVar3 * 0x10 + *(int *)(iVar1 + 0xcbc));
  }
  else {
    pnVar2 = (nwk_route_t *)0x0;
  }
  return pnVar2;
}

