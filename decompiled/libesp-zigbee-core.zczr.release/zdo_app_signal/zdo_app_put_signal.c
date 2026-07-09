/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_signal.o -> zdo_app_put_signal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_app_put_signal(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  
  uVar1 = 0;
  while( true ) {
    iVar2 = core_globals_get();
    if (*(byte *)(iVar2 + 0xcbc) <= uVar1) {
      return;
    }
    iVar3 = core_globals_get();
    iVar2 = (uVar1 + 0x328) * 4;
    if (*(int *)(iVar3 + iVar2 + 0x10) == 0) {
      __assert_func(0,0,0,0);
    }
    iVar3 = core_globals_get();
    pcVar4 = *(code **)(iVar3 + iVar2 + 0x10);
    iVar2 = (*pcVar4)(param_1,pcVar4);
    if (iVar2 != 0) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return;
}

