/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_lqa_2_cost
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t nwk_lqa_2_cost(uint8_t lqa)

{
  undefined3 in_register_00002029;
  uint uVar1;
  
  uVar1 = CONCAT31(in_register_00002029,lqa);
  if (uVar1 != 0) {
    if (uVar1 < 0x11) {
      return '\a';
    }
    if (uVar1 < 0x21) {
      return '\x06';
    }
    if (uVar1 < 0x41) {
      return '\x05';
    }
    if (uVar1 < 0x61) {
      return '\x04';
    }
    if (0x80 < uVar1) {
      return (uVar1 < 0xc1) + '\x01';
    }
    uVar1 = 3;
  }
  return (uint8_t)uVar1;
}

