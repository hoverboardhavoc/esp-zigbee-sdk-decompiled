/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_link_mngr.o -> nwk_link_mngr_handle_link_status_period
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_link_mngr_handle_link_status_period(void)

{
  int iVar1;
  int iVar2;
  
  nwk_neighbor_table_handle_link_status_period();
  nwk_route_table_handle_link_status_period();
  iVar1 = core_globals_get();
  iVar2 = core_globals_get();
  nwk_link_mngr_start_timer(iVar1 + 0xaf4,*(undefined1 *)(iVar2 + 0xa24),0);
  return;
}

