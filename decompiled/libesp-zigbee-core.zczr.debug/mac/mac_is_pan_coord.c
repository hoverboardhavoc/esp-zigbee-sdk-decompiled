/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_is_pan_coord
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool mac_is_pan_coord(mac_device *dev)

{
  ezb_shortaddr_t eVar1;
  
  eVar1 = (dev->pib).coord_shortaddr;
  if (eVar1 == 0xffff) {
    return false;
  }
  if (eVar1 != (dev->pib).short_address) {
    return false;
  }
  return true;
}

