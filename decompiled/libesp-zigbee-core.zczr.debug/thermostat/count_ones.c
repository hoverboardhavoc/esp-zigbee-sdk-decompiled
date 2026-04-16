/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> count_ones
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t count_ones(uint8_t x)

{
  uint8_t uVar1;
  undefined3 in_register_00002029;
  uint uVar2;
  
  uVar1 = '\0';
  for (uVar2 = CONCAT31(in_register_00002029,x); uVar2 != 0; uVar2 = uVar2 & uVar2 - 1) {
    uVar1 = uVar1 + '\x01';
  }
  return uVar1;
}

