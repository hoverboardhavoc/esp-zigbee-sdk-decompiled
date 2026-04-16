/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_signal.o -> zdo_app_signal_dispatch
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_app_signal_dispatch(zdo_app_signal_t *signal)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  
  uVar1 = 0;
  while( true ) {
    iVar2 = core_globals_get();
    if (*(byte *)(iVar2 + 0xd20) <= uVar1) {
      return;
    }
    iVar2 = core_globals_get();
    if (*(int *)(iVar2 + (uVar1 + 0x340) * 4 + 0x14) == 0) break;
    iVar2 = core_globals_get();
    pcVar3 = *(code **)(iVar2 + (uVar1 + 0x340) * 4 + 0x14);
    iVar2 = (*pcVar3)(signal,pcVar3);
    if (iVar2 != 0) {
      return;
    }
    uVar1 = uVar1 + 1 & 0xff;
  }
  __assert_func("//build/esp-zigbee/src/core/zdo/zdo_app_signal.c",0x3c,"zdo_app_signal_dispatch",
                0x10000);
  return;
}

