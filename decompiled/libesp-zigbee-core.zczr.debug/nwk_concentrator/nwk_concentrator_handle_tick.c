/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_concentrator.o -> nwk_concentrator_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_concentrator_handle_tick(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = core_globals_get();
  if (*(char *)(iVar2 + 0x9f7) == '\0') {
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_concentrator.c",0x31,
                  "nwk_concentrator_handle_tick",0x10000);
  }
  else {
    iVar2 = core_globals_get();
    bVar1 = *(byte *)(iVar2 + 0x9f8);
    iVar2 = core_globals_get();
    if (bVar1 < *(byte *)(iVar2 + 0x9fa)) {
      iVar2 = core_globals_get();
      *(char *)(iVar2 + 0x9f8) = *(char *)(iVar2 + 0x9f8) + '\x01';
      return;
    }
  }
  iVar2 = core_globals_get();
  *(undefined1 *)(iVar2 + 0x9f8) = 0;
  iVar2 = core_globals_get();
  nwk_mesh_route_discovery(1,0xfffc,*(undefined1 *)(iVar2 + 0x9f9));
  return;
}

