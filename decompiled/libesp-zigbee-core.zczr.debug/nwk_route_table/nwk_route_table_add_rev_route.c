/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_table_add_rev_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_route_table_add_rev_route
                    (ezb_shortaddr_t dst_addr,ezb_shortaddr_t next_hop,nwk_rreq_type_t rreq_type)

{
  undefined2 in_register_0000202a;
  nwk_route_t *route;
  ezb_err_t eVar1;
  undefined2 in_register_0000202e;
  
  if (CONCAT22(in_register_0000202a,dst_addr) < 0xfff8) {
    if (CONCAT22(in_register_0000202e,next_hop) < 0xfff8) {
      if (CONCAT22(in_register_0000202a,dst_addr) == CONCAT22(in_register_0000202e,next_hop)) {
        eVar1 = 2;
      }
      else {
        route = nwk_route_table_find_or_create(dst_addr);
        if (route == (nwk_route_t *)0x0) {
          eVar1 = 1;
        }
        else {
          nwk_route_table_update_rev_route(route,next_hop,rreq_type);
          eVar1 = 0;
        }
      }
    }
    else {
      eVar1 = 2;
    }
  }
  else {
    eVar1 = 2;
  }
  return eVar1;
}

