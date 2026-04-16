/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_network_status_to_str
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

char * nwk_network_status_to_str(nwk_network_status_t status)

{
  undefined3 in_register_00002029;
  uint uVar1;
  
  uVar1 = CONCAT31(in_register_00002029,status);
  if (uVar1 == 0xc) {
    return "MTO-Route failure";
  }
  if (uVar1 < 0xd) {
    if (uVar1 == 2) {
      return "Link failure";
    }
    if (uVar1 < 3) {
      if (uVar1 != 0) {
        return "Legacy link failure";
      }
      return "Legacy no route";
    }
    if (uVar1 == 9) {
      return "ParentLink failure";
    }
    if (uVar1 == 0xb) {
      return "SourceRoute failure";
    }
  }
  else {
    if (uVar1 == 0x10) {
      return "Address update";
    }
    if (uVar1 < 0x11) {
      if (uVar1 == 0xd) {
        return "Address conflict";
      }
      if (uVar1 == 0xf) {
        return "PANID update";
      }
    }
    else {
      if (uVar1 == 0x13) {
        return "Command unknown";
      }
      if (uVar1 == 0x14) {
        return "PANID conflict";
      }
    }
  }
  return "Unknown";
}

