/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_disc_table_find_or_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_route_disc_t * nwk_route_disc_table_find_or_create(ezb_shortaddr_t src_addr,uint8_t rreq_id)

{
  int iVar1;
  nwk_route_disc_t *pnVar2;
  
  iVar1 = core_globals_get();
  pnVar2 = route_disc_table_find((nwk_route_disc_table_t *)(iVar1 + 0xcc8),src_addr,rreq_id);
  if (pnVar2 == (nwk_route_disc_t *)0x0) {
    pnVar2 = route_disc_table_create((nwk_route_disc_table_t *)(iVar1 + 0xcc8),src_addr,rreq_id);
  }
  return pnVar2;
}

