/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_frame.o -> nwk_fcf_get_hdr_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t nwk_fcf_get_hdr_size(uint16_t fcf)

{
  uint8_t uVar1;
  
  if ((fcf & 0x800) == 0) {
    uVar1 = '\b';
  }
  else {
    uVar1 = '\x10';
  }
  if ((fcf & 0x1000) != 0) {
    uVar1 = uVar1 + '\b';
  }
  if ((fcf & 0x100) != 0) {
    uVar1 = uVar1 + '\x01';
  }
  return uVar1;
}

