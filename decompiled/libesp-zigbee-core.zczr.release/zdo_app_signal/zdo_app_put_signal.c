/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_signal.o -> zdo_app_put_signal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_app_put_signal(zdo_app_signal_t *signal)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  
  uVar1 = 0;
  while( true ) {
    iVar2 = core_globals_get();
    if (*(byte *)(iVar2 + 0xd20) <= uVar1) {
      return;
    }
    iVar3 = core_globals_get();
    iVar2 = (uVar1 + 0x340) * 4;
    if (*(int *)(iVar3 + iVar2 + 0x14) == 0) {
      __assert_func(0,0,0,0);
    }
    iVar3 = core_globals_get();
    pcVar4 = *(code **)(iVar3 + iVar2 + 0x14);
    iVar2 = (*pcVar4)(signal,pcVar4);
    if (iVar2 != 0) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return;
}

