/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_reporting_deinit(void)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  milli_timer_stop(iVar1 + 0xd24);
  iVar1 = core_globals_get();
  milli_timer_init(iVar1 + 0xd24,0,0);
  zcl_reporting_info_free();
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xd20) = 0;
  return;
}

