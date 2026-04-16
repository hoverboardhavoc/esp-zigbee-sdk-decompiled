/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_start_discovery
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_route_start_discovery(nwk_route_t *route,nwk_route_disc_t *route_disc)

{
  ushort uVar1;
  uint uVar2;
  nwk_route_disc_t *extraout_a1;
  
  if (route_disc->route == (nwk_route_t *)0x0) goto _L0;
  do {
    route = (nwk_route_t *)__assert_func(0,0,0,0);
    route_disc = extraout_a1;
_L0:
    if ((*(ushort *)&route->field_0xe & 7) != 0) {
      *(ushort *)&route->field_0xe = *(ushort *)&route->field_0xe & 0xfff8 | 1;
    }
    uVar1 = route_disc->src_addr;
    uVar2 = nwk_get_short_address();
    if (uVar1 != uVar2) goto _L0;
  } while (route->initiator == 0xff);
  route->initiator = route->initiator + '\x01';
_L0:
  route_disc->route = route;
  route->ref = route->ref + '\x01';
  return;
}

