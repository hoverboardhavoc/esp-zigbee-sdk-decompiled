/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_record_table_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_route_record_t * nwk_route_record_table_next(nwk_route_record_t *route_record)

{
  int iVar1;
  nwk_route_record_t *pnVar2;
  uint uVar3;
  
  iVar1 = core_globals_get();
  if (route_record == (nwk_route_record_t *)0x0) {
    uVar3 = 0xffff;
  }
  else {
    uVar3 = ((int)route_record - *(int *)(iVar1 + 0xcd4) >> 2) * -0x49249249 & 0xffff;
  }
  uVar3 = bitmap_find_next_bit
                    (*(undefined4 *)(iVar1 + 0xcd8),*(undefined2 *)(iVar1 + 0xcdc),
                     uVar3 + 1 & 0xffff);
  pnVar2 = (nwk_route_record_t *)0x0;
  if (uVar3 < *(ushort *)(iVar1 + 0xcdc)) {
    pnVar2 = (nwk_route_record_t *)(*(int *)(iVar1 + 0xcd4) + uVar3 * 0x1c);
  }
  return pnVar2;
}

