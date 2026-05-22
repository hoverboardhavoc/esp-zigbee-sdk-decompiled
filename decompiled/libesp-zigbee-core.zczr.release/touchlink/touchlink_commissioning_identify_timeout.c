/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_commissioning_identify_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_commissioning_identify_timeout(void *arg)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  
  iVar3 = core_globals_get();
  sVar1 = *(short *)(iVar3 + 0x13cc);
  *(short *)(iVar3 + 0x13cc) = sVar1 + -1;
  if (sVar1 == 0) {
    iVar3 = core_globals_get();
    milli_timer_stop(iVar3 + 0x13d0);
    return;
  }
  iVar3 = core_globals_get();
  uVar2 = *(undefined2 *)(iVar3 + 0x13cc);
  iVar3 = core_globals_get();
  if (*(int *)(iVar3 + 0x13e0) == 0) {
    return;
  }
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 0x13cc) = uVar2;
  iVar3 = core_globals_get();
  (**(code **)(iVar3 + 0x13e0))(uVar2,*(code **)(iVar3 + 0x13e0));
  iVar3 = core_globals_get();
  milli_timer_stop(iVar3 + 0x13d0);
  iVar3 = core_globals_get();
  milli_timer_init(iVar3 + 0x13d0,touchlink_commissioning_identify_timeout,0);
  iVar3 = core_globals_get();
  milli_timer_start(iVar3 + 0x13d0,1000);
  return;
}

