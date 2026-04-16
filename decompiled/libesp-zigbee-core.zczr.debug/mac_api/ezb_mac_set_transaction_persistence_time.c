/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac_api.o -> ezb_mac_set_transaction_persistence_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_mac_set_transaction_persistence_time(uint32_t us)

{
  ezb_err_t eVar1;
  undefined2 auStack_12 [2];
  uint16_t t;
  
  auStack_12[0] = (undefined2)(us / 0x3c00);
  eVar1 = nwk_mm_set_pib_attr(0,0x55,auStack_12);
  return eVar1;
}

