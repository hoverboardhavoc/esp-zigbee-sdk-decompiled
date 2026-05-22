/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_signal.o -> zdo_app_signal_remove_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_app_signal_remove_handler(zdo_app_signal_handler_t handler)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (handler == (zdo_app_signal_handler_t)0x0) {
    return;
  }
  uVar1 = 0;
  while( true ) {
    iVar2 = core_globals_get();
    if (*(byte *)(iVar2 + 0xcbc) <= uVar1) {
      return;
    }
    iVar2 = core_globals_get();
    if (*(zdo_app_signal_handler_t *)(iVar2 + (uVar1 + 0x328) * 4 + 0x10) == handler) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  iVar3 = core_globals_get();
  iVar2 = (uVar1 + 0x32c) * 4;
  iVar4 = core_globals_get();
  iVar5 = core_globals_get();
  memmove((void *)(iVar3 + iVar2),(void *)(iVar2 + 4 + iVar4),
          ((*(byte *)(iVar5 + 0xcbc) - uVar1) + -1) * 4);
  iVar2 = core_globals_get();
  *(char *)(iVar2 + 0xcbc) = *(char *)(iVar2 + 0xcbc) + -1;
  iVar2 = core_globals_get();
  iVar3 = core_globals_get();
  *(undefined4 *)(iVar2 + (*(byte *)(iVar3 + 0xcbc) + 0x328) * 4 + 0x10) = 0;
  return;
}

