/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_api.o -> ezb_mac_get_transaction_persistence_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_mac_get_transaction_persistence_time(void)

{
  ushort auStack_12 [7];
  
  auStack_12[0] = 0;
  nwk_mm_get_pib_attr(0,0x55,auStack_12,2);
  return (uint)auStack_12[0] * 0x3c00;
}

