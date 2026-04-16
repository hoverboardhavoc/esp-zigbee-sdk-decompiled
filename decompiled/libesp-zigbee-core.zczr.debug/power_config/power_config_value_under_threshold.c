/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> power_config.o -> power_config_value_under_threshold
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool power_config_value_under_threshold(uint8_t value,uint8_t threshold)

{
  undefined3 in_register_00002029;
  undefined3 in_register_0000202d;
  
  if (CONCAT31(in_register_0000202d,threshold) <= CONCAT31(in_register_00002029,value)) {
    return false;
  }
  if (CONCAT31(in_register_0000202d,threshold) != 0xff) {
    return true;
  }
  return false;
}

