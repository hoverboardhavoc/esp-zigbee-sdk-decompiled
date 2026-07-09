/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_concentrator.o -> nwk_concentrator_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_concentrator_handle_tick(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = core_globals_get();
  if (*(char *)(iVar2 + 0x9f7) == '\0') {
    __assert_func(0,0,0,0);
  }
  iVar2 = core_globals_get();
  bVar1 = *(byte *)(iVar2 + 0x9f8);
  iVar2 = core_globals_get();
  if (bVar1 < *(byte *)(iVar2 + 0x9fa)) {
    iVar2 = core_globals_get();
    *(char *)(iVar2 + 0x9f8) = *(char *)(iVar2 + 0x9f8) + '\x01';
    return;
  }
  iVar2 = core_globals_get();
  *(undefined1 *)(iVar2 + 0x9f8) = 0;
  iVar2 = core_globals_get();
  nwk_mesh_route_discovery(1,0xfffc,*(undefined1 *)(iVar2 + 0x9f9));
  return;
}

