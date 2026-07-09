/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_signal.o -> zdo_app_signal_add_handler_front
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool zdo_app_signal_add_handler_front(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != 0) {
    iVar2 = core_globals_get();
    bVar1 = 2 < *(byte *)(iVar2 + 0xcbc);
    if (!bVar1) {
      iVar2 = core_globals_get(1);
      iVar3 = core_globals_get();
      iVar4 = core_globals_get();
      memmove((void *)(iVar2 + 0xcb4),(void *)(iVar3 + 0xcb0),(uint)*(byte *)(iVar4 + 0xcbc) << 2);
      iVar2 = core_globals_get();
      *(int *)(iVar2 + 0xcb0) = param_1;
      iVar2 = core_globals_get();
      *(char *)(iVar2 + 0xcbc) = *(char *)(iVar2 + 0xcbc) + '\x01';
    }
    return bVar1;
  }
  return (bool)2;
}

