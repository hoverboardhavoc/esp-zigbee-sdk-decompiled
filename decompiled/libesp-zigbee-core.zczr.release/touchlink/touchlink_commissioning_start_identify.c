/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_commissioning_start_identify
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_commissioning_start_identify(uint16_t duration)

{
  undefined2 in_register_0000202a;
  int iVar1;
  
  iVar1 = core_globals_get();
  if (*(int *)(iVar1 + 0x13e0) != 0) {
    iVar1 = core_globals_get();
    *(uint16_t *)(iVar1 + 0x13cc) = duration;
    iVar1 = core_globals_get();
    (**(code **)(iVar1 + 0x13e0))
              (CONCAT22(in_register_0000202a,duration),*(code **)(iVar1 + 0x13e0));
    iVar1 = core_globals_get();
    milli_timer_stop(iVar1 + 0x13d0);
    iVar1 = core_globals_get();
    milli_timer_init(iVar1 + 0x13d0,touchlink_commissioning_identify_timeout,0);
    iVar1 = core_globals_get();
    milli_timer_start(iVar1 + 0x13d0,1000);
    return;
  }
  return;
}

