/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  if (*(int *)(iVar1 + 0x1434) != 0) {
    iVar1 = core_globals_get();
    *(uint16_t *)(iVar1 + 0x1420) = duration;
    iVar1 = core_globals_get();
    (**(code **)(iVar1 + 0x1434))
              (CONCAT22(in_register_0000202a,duration),*(code **)(iVar1 + 0x1434));
    iVar1 = core_globals_get();
    milli_timer_stop(iVar1 + 0x1424);
    iVar1 = core_globals_get();
    milli_timer_init(iVar1 + 0x1424,touchlink_commissioning_identify_timeout,0);
    iVar1 = core_globals_get();
    milli_timer_start(iVar1 + 0x1424,1000);
    return;
  }
  return;
}

