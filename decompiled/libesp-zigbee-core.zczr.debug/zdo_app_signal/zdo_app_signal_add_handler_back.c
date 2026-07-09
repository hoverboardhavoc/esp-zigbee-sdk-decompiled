/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_signal.o -> zdo_app_signal_add_handler_back
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_app_signal_add_handler_back(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    uVar2 = 2;
  }
  else {
    iVar1 = core_globals_get();
    if (*(byte *)(iVar1 + 0xcbc) < 3) {
      iVar1 = core_globals_get();
      iVar3 = core_globals_get();
      *(int *)(iVar1 + (*(byte *)(iVar3 + 0xcbc) + 0x328) * 4 + 0x10) = param_1;
      iVar1 = core_globals_get();
      *(char *)(iVar1 + 0xcbc) = *(char *)(iVar1 + 0xcbc) + '\x01';
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}

