/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_api.o -> ezb_nwk_set_max_children
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_nwk_set_max_children(uint8_t max_children)

{
  int iVar1;
  ezb_err_t eVar2;
  
  iVar1 = nwk_is_device_zczr();
  if (iVar1 == 0) {
    eVar2 = 6;
  }
  else {
    iVar1 = core_globals_get();
    *(uint8_t *)(iVar1 + 0x9db) = max_children;
    eVar2 = 0;
  }
  return eVar2;
}

