/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_table_update_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_route_table_update_route(nwk_route_t *route,ezb_shortaddr_t next_hop)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = *(ushort *)&route->field_0xe;
  route->next_hop = next_hop;
  *(ushort *)&route->field_0xe = uVar2 & 0xfff8;
  if ((uVar2 & 7) != 1) {
    return;
  }
  bVar1 = route->field_0xf;
  *(ushort *)&route->field_0xe = *(ushort *)&route->field_0xe & 0xfeff;
  nwk_fwd_handle_route_disc_done(route->dst_addr,0);
  if ((bVar1 & 1) != 0) {
    nwk_mesh_route_discovery_done(route->dst_addr,0,0);
    return;
  }
  return;
}

