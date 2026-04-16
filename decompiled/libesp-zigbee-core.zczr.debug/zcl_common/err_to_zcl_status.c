/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_common.o -> err_to_zcl_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t err_to_zcl_status(ezb_err_t error)

{
  if (error == 4) {
    return 0x85;
  }
  if (error < 5) {
    if (error == 2) {
      return 0x87;
    }
    if (2 < error) {
      if (error == 3) {
        return '~';
      }
      return '\x01';
    }
    if (error == 0) {
      return '\0';
    }
    if (error == 1) {
      return 0x89;
    }
    return '\x01';
  }
  if (error == 8) {
    return 0x95;
  }
  if (8 < error) {
    if (error == 0xc) {
      return 0x97;
    }
    return '\x01';
  }
  if (error == 5) {
    return 0x8b;
  }
  if (error == 7) {
    return 0x94;
  }
  return '\x01';
}

