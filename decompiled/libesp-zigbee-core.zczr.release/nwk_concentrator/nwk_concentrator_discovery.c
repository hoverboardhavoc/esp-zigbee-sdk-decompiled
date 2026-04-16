/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_concentrator.o -> nwk_concentrator_discovery
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_concentrator_discovery(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  ezb_err_t eVar4;
  
  iVar3 = nwk_is_device_zczr();
  eVar4 = 6;
  if (iVar3 != 0) {
    iVar3 = core_globals_get();
    eVar4 = 3;
    if (*(char *)(iVar3 + 0x9f7) != '\0') {
      iVar3 = core_globals_get();
      cVar1 = *(char *)(iVar3 + 0x9fa);
      iVar3 = core_globals_get();
      cVar2 = *(char *)(iVar3 + 0x9fb);
      iVar3 = core_globals_get();
      *(char *)(iVar3 + 0x9f8) = (cVar1 + *(char *)(iVar3 + 0x9f8)) - cVar2;
      nwk_concentrator_handle_tick();
      eVar4 = 0;
    }
  }
  return eVar4;
}

