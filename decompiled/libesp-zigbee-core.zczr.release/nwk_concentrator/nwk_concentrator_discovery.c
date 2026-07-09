/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_concentrator.o -> nwk_concentrator_discovery
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_concentrator_discovery(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = nwk_is_device_zczr();
  uVar4 = 6;
  if (iVar3 != 0) {
    iVar3 = core_globals_get();
    uVar4 = 3;
    if (*(char *)(iVar3 + 0x9f7) != '\0') {
      iVar3 = core_globals_get();
      cVar1 = *(char *)(iVar3 + 0x9fa);
      iVar3 = core_globals_get();
      cVar2 = *(char *)(iVar3 + 0x9fb);
      iVar3 = core_globals_get();
      *(char *)(iVar3 + 0x9f8) = (cVar1 + *(char *)(iVar3 + 0x9f8)) - cVar2;
      nwk_concentrator_handle_tick();
      uVar4 = 0;
    }
  }
  return uVar4;
}

