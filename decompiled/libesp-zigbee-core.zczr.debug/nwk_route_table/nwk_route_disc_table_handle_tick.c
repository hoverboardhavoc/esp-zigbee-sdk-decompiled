/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_disc_table_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_route_disc_table_handle_tick(void)

{
  int iVar1;
  nwk_route_disc_t *route_disc;
  uint uVar2;
  
  iVar1 = core_globals_get();
  uVar2 = 0;
  while (uVar2 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar1 + 0xccc),*(undefined2 *)(iVar1 + 0xcd0),uVar2),
        uVar2 < *(ushort *)(iVar1 + 0xcd0)) {
    route_disc = (nwk_route_disc_t *)(*(int *)(iVar1 + 0xcc8) + uVar2 * 0x10);
    if (route_disc->expiry == 0) {
      nwk_route_disc_table_delete(route_disc);
    }
    else {
      route_disc->expiry = route_disc->expiry - 1;
    }
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return;
}

