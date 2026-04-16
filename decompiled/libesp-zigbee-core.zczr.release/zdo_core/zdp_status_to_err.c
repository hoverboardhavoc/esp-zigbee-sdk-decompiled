/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_core.o -> zdp_status_to_err
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdp_status_to_err(zdp_status_t status)

{
  undefined3 in_register_00002029;
  uint uVar1;
  ezb_err_t eVar2;
  
  uVar1 = CONCAT31(in_register_00002029,status);
  if (uVar1 == 0x84) {
    eVar2 = 6;
  }
  else if (uVar1 < 0x85) {
    eVar2 = 0;
    if ((uVar1 != 0) && (eVar2 = -1, uVar1 == 0x80)) {
      return 2;
    }
  }
  else {
    eVar2 = 7;
    if ((uVar1 != 0x85) && (eVar2 = -1, uVar1 == 0x8a)) {
      return 1;
    }
  }
  return eVar2;
}

