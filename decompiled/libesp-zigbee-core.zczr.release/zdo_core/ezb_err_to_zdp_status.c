/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_core.o -> ezb_err_to_zdp_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t ezb_err_to_zdp_status(ezb_err_t error)

{
  zdp_status_t zVar1;
  
  if (error == 6) {
    zVar1 = 0x84;
  }
  else if (error < 7) {
    zVar1 = '\0';
    if ((error != 0) && (zVar1 = 0x80, error == 1)) {
      return 0x8a;
    }
  }
  else {
    zVar1 = 0x80;
    if (error == 7) {
      return 0x85;
    }
  }
  return zVar1;
}

