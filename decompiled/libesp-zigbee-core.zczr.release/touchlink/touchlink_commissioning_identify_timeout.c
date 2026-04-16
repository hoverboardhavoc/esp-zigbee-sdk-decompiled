/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  sVar1 = *(short *)(iVar3 + 0x1420);
  *(short *)(iVar3 + 0x1420) = sVar1 + -1;
  if (sVar1 == 0) {
    iVar3 = core_globals_get();
    milli_timer_stop(iVar3 + 0x1424);
    return;
  }
  iVar3 = core_globals_get();
  uVar2 = *(undefined2 *)(iVar3 + 0x1420);
  iVar3 = core_globals_get();
  if (*(int *)(iVar3 + 0x1434) == 0) {
    return;
  }
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 0x1420) = uVar2;
  iVar3 = core_globals_get();
  (**(code **)(iVar3 + 0x1434))(uVar2,*(code **)(iVar3 + 0x1434));
  iVar3 = core_globals_get();
  milli_timer_stop(iVar3 + 0x1424);
  iVar3 = core_globals_get();
  milli_timer_init(iVar3 + 0x1424,touchlink_commissioning_identify_timeout,0);
  iVar3 = core_globals_get();
  milli_timer_start(iVar3 + 0x1424,1000);
  return;
}

