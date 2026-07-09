/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_ed_init_keepalive
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_ed_init_keepalive(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = core_globals_get();
  milli_timer_init(iVar1 + 0xae4,nwk_ed_handle_keepalive_timer,0);
  iVar1 = core_globals_get();
  uVar2 = nwk_ed_get_default_keepalive_interval();
  *(undefined4 *)(iVar1 + 0xaf4) = uVar2;
  nwk_ed_stop_keepalive();
  return;
}

