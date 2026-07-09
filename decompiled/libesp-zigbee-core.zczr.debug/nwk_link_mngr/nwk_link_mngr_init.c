/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_link_mngr.o -> nwk_link_mngr_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_link_mngr_init(void)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  milli_timer_init(iVar1 + 0xaf4,nwk_link_mngr_handle_link_status_period,0);
  iVar1 = core_globals_get();
  milli_timer_init(iVar1 + 0xae4,nwk_link_mngr_send_link_status_cmd,0);
  return;
}

