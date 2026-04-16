/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_api.o -> ezb_aps_set_channel_mask
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_aps_set_channel_mask(uint32_t channel_mask)

{
  int iVar1;
  ezb_err_t eVar2;
  
  if (channel_mask < 0x8000000) {
    if ((channel_mask & 0x7ffffff) < 0x800) {
      eVar2 = 2;
    }
    else {
      iVar1 = core_globals_get();
      *(uint32_t *)(iVar1 + 8) = channel_mask;
      eVar2 = 0;
    }
  }
  else {
    eVar2 = 2;
  }
  return eVar2;
}

