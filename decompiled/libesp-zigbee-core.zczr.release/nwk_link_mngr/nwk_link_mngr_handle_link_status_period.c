/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_link_mngr.o -> nwk_link_mngr_handle_link_status_period
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_link_mngr_handle_link_status_period(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  nwk_neighbor_table_handle_link_status_period();
  nwk_route_table_handle_link_status_period();
  iVar2 = core_globals_get();
  iVar3 = core_globals_get();
  uVar1 = random_add_jitter((uint)*(byte *)(iVar3 + 0xa24) * 1000,0);
  milli_timer_start(iVar2 + 0xaf4,uVar1);
  return;
}

