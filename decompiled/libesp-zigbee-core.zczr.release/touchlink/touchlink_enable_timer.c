/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_enable_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_enable_timer(timer_func_t timer_func,uint32_t delay_ms,void *arg)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  milli_timer_init(iVar1 + 0x13ec,timer_func,arg);
  iVar1 = core_globals_get();
  milli_timer_start(iVar1 + 0x13ec,delay_ms);
  return;
}

