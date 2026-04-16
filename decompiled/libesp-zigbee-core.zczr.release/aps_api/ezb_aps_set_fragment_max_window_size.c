/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_api.o -> ezb_aps_set_fragment_max_window_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_aps_set_fragment_max_window_size(uint8_t max_window_size)

{
  int iVar1;
  
  if ((byte)(max_window_size - 1) < 8) {
    iVar1 = core_globals_get();
    *(uint8_t *)(iVar1 + 2) = max_window_size;
    return 0;
  }
  return 2;
}

