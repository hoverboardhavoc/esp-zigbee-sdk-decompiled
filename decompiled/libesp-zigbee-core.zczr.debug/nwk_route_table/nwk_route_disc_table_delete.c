/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_disc_table_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_route_disc_table_delete(nwk_route_disc_t *route_disc)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  nwk_route_disc_t *route_disc_00;
  nwk_route_t *route;
  void *blk_base;
  bitmap_t *blk_busy;
  
  route = route_disc->route;
  uVar1 = route_disc->src_addr;
  uVar2 = nwk_get_short_address();
  iVar3 = core_globals_get();
  blk_base = *(void **)(iVar3 + 0xc64);
  iVar3 = core_globals_get();
  blk_busy = *(bitmap_t **)(iVar3 + 0xc68);
  iVar3 = core_globals_get();
  mempool_free_ent(blk_base,blk_busy,0x10,*(uint16_t *)(iVar3 + 0xc6c),route_disc);
  if (route != (nwk_route_t *)0x0) {
    if (uVar1 == uVar2) {
      if (route->initiator == '\0') {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_route_table.c",0x1a0,
                      "nwk_route_disc_table_delete","route->initiator > 0");
        iVar3 = core_globals_get();
        uVar2 = 0;
        while (uVar2 = bitmap_find_next_bit
                                 (*(undefined4 *)(iVar3 + 0xc68),*(undefined2 *)(iVar3 + 0xc6c),
                                  uVar2), uVar2 < *(ushort *)(iVar3 + 0xc6c)) {
          route_disc_00 = (nwk_route_disc_t *)(*(int *)(iVar3 + 0xc64) + uVar2 * 0x10);
          if (route_disc_00->expiry == 0) {
            nwk_route_disc_table_delete(route_disc_00);
          }
          else {
            route_disc_00->expiry = route_disc_00->expiry - 1;
          }
          uVar2 = uVar2 + 1 & 0xffff;
        }
        return;
      }
      route->initiator = route->initiator + 0xff;
    }
    nwk_route_finish_discovery(route);
  }
  return;
}

