/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
    if (*(byte *)(iVar2 + 0xd20) <= uVar1) {
      return;
    }
    iVar2 = core_globals_get();
    if (*(zdo_app_signal_handler_t *)(iVar2 + (uVar1 + 0x340) * 4 + 0x14) == handler) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  iVar3 = core_globals_get();
  iVar2 = (uVar1 + 0x345) * 4;
  iVar4 = core_globals_get();
  iVar5 = core_globals_get();
  memmove((void *)(iVar3 + iVar2),(void *)(iVar2 + 4 + iVar4),
          ((*(byte *)(iVar5 + 0xd20) - uVar1) + -1) * 4);
  iVar2 = core_globals_get();
  *(char *)(iVar2 + 0xd20) = *(char *)(iVar2 + 0xd20) + -1;
  iVar2 = core_globals_get();
  iVar3 = core_globals_get();
  *(undefined4 *)(iVar2 + (*(byte *)(iVar3 + 0xd20) + 0x340) * 4 + 0x14) = 0;
  return;
}

