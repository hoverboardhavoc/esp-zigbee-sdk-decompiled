/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_signal.o -> zdo_app_signal_dispatch
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_app_signal_dispatch(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  
  uVar1 = 0;
  while( true ) {
    iVar2 = core_globals_get();
    if (*(byte *)(iVar2 + 0xcbc) <= uVar1) {
      return;
    }
    iVar2 = core_globals_get();
    if (*(int *)(iVar2 + (uVar1 + 0x328) * 4 + 0x10) == 0) break;
    iVar2 = core_globals_get();
    pcVar3 = *(code **)(iVar2 + (uVar1 + 0x328) * 4 + 0x10);
    iVar2 = (*pcVar3)(param_1,pcVar3);
    if (iVar2 != 0) {
      return;
    }
    uVar1 = uVar1 + 1 & 0xff;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_app_signal.c",0x3c,
                "zdo_app_signal_dispatch",0x10000);
  return;
}

