/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_start_discovery
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_route_start_discovery(nwk_route_t *route,nwk_route_disc_t *route_disc)

{
  ushort uVar1;
  ezb_shortaddr_t dst_addr;
  uint uVar2;
  nwk_route_t *obj;
  int iVar3;
  void *blk_base;
  bitmap_t *blk_busy;
  
  if (route_disc->route == (nwk_route_t *)0x0) {
    if ((*(ushort *)&route->field_0xe & 7) != 0) {
      *(ushort *)&route->field_0xe = *(ushort *)&route->field_0xe & 0xfff8 | 1;
    }
    uVar1 = route_disc->src_addr;
    uVar2 = nwk_get_short_address();
    if (uVar1 != uVar2) goto _L0;
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_route_table.c",0xfd,
                  "nwk_route_start_discovery","route_disc->route == ((void *)0)");
  }
  if (route->initiator == 0xff) {
    dst_addr = __assert_func("//build/esp-zigbee/src/core/nwk/nwk_route_table.c",0x104,
                             "nwk_route_start_discovery","route->initiator < (0xff)");
    obj = nwk_route_table_find(dst_addr);
    if (obj != (nwk_route_t *)0x0) {
      if (obj->ref == '\0') {
        iVar3 = core_globals_get();
        blk_base = *(void **)(iVar3 + 0xcbc);
        iVar3 = core_globals_get();
        blk_busy = *(bitmap_t **)(iVar3 + 0xcc0);
        iVar3 = core_globals_get();
        mempool_free_ent(blk_base,blk_busy,0x10,*(uint16_t *)(iVar3 + 0xcc4),obj);
      }
      else {
        *(ushort *)&obj->field_0xe = *(ushort *)&obj->field_0xe & 0xfff8 | 1;
      }
    }
    return;
  }
  route->initiator = route->initiator + '\x01';
_L0:
  route_disc->route = route;
  route->ref = route->ref + '\x01';
  return;
}

