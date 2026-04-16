/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_core.o -> ezb_err_to_zdp_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t ezb_err_to_zdp_status(ezb_err_t error)

{
  if (error == 2) {
    return 0x80;
  }
  if (error < 3) {
    if (error == 0) {
      return '\0';
    }
    if (error == 1) {
      return 0x8a;
    }
    return 0x80;
  }
  if (error == 6) {
    return 0x84;
  }
  if (error == 7) {
    return 0x85;
  }
  return 0x80;
}

