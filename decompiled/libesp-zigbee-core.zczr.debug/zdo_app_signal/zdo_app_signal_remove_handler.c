/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_signal.o -> zdo_app_signal_remove_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_app_signal_remove_handler(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != 0) {
    for (uVar1 = 0; iVar2 = core_globals_get(), uVar1 < *(byte *)(iVar2 + 0xcbc);
        uVar1 = uVar1 + 1 & 0xff) {
      iVar2 = core_globals_get();
      if (*(int *)(iVar2 + (uVar1 + 0x328) * 4 + 0x10) == param_1) {
        iVar2 = core_globals_get();
        iVar3 = core_globals_get();
        iVar4 = core_globals_get();
        memmove((void *)(iVar2 + (uVar1 + 0x328) * 4 + 0x10),
                (void *)(iVar3 + (uVar1 + 0x329) * 4 + 0x10),
                ((*(byte *)(iVar4 + 0xcbc) - uVar1) + -1) * 4);
        iVar2 = core_globals_get();
        *(char *)(iVar2 + 0xcbc) = *(char *)(iVar2 + 0xcbc) + -1;
        iVar2 = core_globals_get();
        iVar3 = core_globals_get();
        *(undefined4 *)(iVar2 + (*(byte *)(iVar3 + 0xcbc) + 0x328) * 4 + 0x10) = 0;
        return;
      }
    }
  }
  return;
}

