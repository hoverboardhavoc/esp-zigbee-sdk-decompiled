/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_common.o -> err_to_zcl_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t err_to_zcl_status(ezb_err_t error)

{
  zcl_status_t zVar1;
  
  if (error == 4) {
    zVar1 = 0x85;
  }
  else if (error < 5) {
    zVar1 = 0x87;
    if ((((error != 2) && (zVar1 = '~', error != 3)) && (zVar1 = '\0', error != 0)) &&
       (zVar1 = '\x01', error == 1)) {
      return 0x89;
    }
  }
  else {
    zVar1 = 0x95;
    if (error != 8) {
      if (error < 9) {
        zVar1 = 0x8b;
        if ((error != 5) && (zVar1 = '\x01', error == 7)) {
          return 0x94;
        }
      }
      else {
        zVar1 = '\x01';
        if (error == 0xc) {
          return 0x97;
        }
      }
    }
  }
  return zVar1;
}

