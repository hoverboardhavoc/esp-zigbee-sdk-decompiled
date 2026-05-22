/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
    iVar2 = (*pcVar4)(signal,pcVar4);
    if (iVar2 != 0) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return;
}

