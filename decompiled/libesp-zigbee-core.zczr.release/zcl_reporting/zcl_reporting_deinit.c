/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

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

