/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_finish_discovery
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_route_finish_discovery(nwk_route_t *route)

{
  uint8_t uVar1;
  byte bVar2;
  ezb_shortaddr_t eVar3;
  _Bool need_confirm;
  nwk_route_t *pnVar4;
  int iVar5;
  ezb_shortaddr_t dst_addr;
  void *blk_base;
  bitmap_t *blk_busy;
  
  uVar1 = route->ref;
  if (uVar1 == '\0') {
    pnVar4 = (nwk_route_t *)
             __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_route_table.c",0x10e,
                           "nwk_route_finish_discovery","route->ref > 0");
  }
  else {
    route->ref = uVar1 + 0xff;
    if (uVar1 != '\x01') {
      return;
    }
    pnVar4 = route;
    if ((*(ushort *)&route->field_0xe & 7) == 0) {
      return;
    }
  }
  bVar2 = pnVar4->field_0xf;
  eVar3 = pnVar4->dst_addr;
  iVar5 = core_globals_get();
  blk_base = *(void **)(iVar5 + 0xc58);
  iVar5 = core_globals_get();
  blk_busy = *(bitmap_t **)(iVar5 + 0xc5c);
  iVar5 = core_globals_get();
  mempool_free_ent(blk_base,blk_busy,0x10,*(uint16_t *)(iVar5 + 0xc60),route);
  nwk_fwd_handle_route_disc_done(eVar3,0x2d0);
  if ((bVar2 & 1) != 0) {
    nwk_mesh_route_discovery_done(eVar3,0x2d0,0);
  }
  return;
}

