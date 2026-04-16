/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_fcf_get_hdr_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t aps_fcf_get_hdr_size(uint8_t fcf)

{
  uint16_t uVar1;
  
  uVar1 = 2;
  if (((fcf & 3) != 1) && (((fcf & 3) != 2 || (uVar1 = 2, (fcf & 0x10) == 0)))) {
    uVar1 = ((fcf & 0xc) == 0xc) + 8;
  }
  return uVar1;
}

