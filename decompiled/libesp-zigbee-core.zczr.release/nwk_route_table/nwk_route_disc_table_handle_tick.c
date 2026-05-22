/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_disc_table_handle_tick
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
                           (*(undefined4 *)(iVar1 + 0xc68),*(undefined2 *)(iVar1 + 0xc6c),uVar2),
        uVar2 < *(ushort *)(iVar1 + 0xc6c)) {
    route_disc = (nwk_route_disc_t *)(*(int *)(iVar1 + 0xc64) + uVar2 * 0x10);
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

