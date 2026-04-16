/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_link_mngr.o -> nwk_link_mngr_handle_link_status_period
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_link_mngr_handle_link_status_period(void)

{
  int iVar1;
  int iVar2;
  
  nwk_neighbor_table_handle_link_status_period();
  nwk_route_table_handle_link_status_period();
  iVar1 = core_globals_get();
  iVar2 = core_globals_get();
  nwk_link_mngr_start_timer((milli_timer_t *)(iVar1 + 0xaf4),*(uint8_t *)(iVar2 + 0xa24),0);
  return;
}

