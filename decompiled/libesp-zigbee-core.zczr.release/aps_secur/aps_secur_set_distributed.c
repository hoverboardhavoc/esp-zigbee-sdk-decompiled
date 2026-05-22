/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_set_distributed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_secur_set_distributed(_Bool enabled)

{
  undefined3 in_register_00002029;
  undefined1 auStack_18 [4];
  ezb_extaddr_t tc_address;
  
  auStack_18 = (undefined1  [4])-CONCAT31(in_register_00002029,enabled);
  tc_address.field_0.u64._0_4_ = -(uint)(CONCAT31(in_register_00002029,enabled) != 0);
  aps_secur_set_tc_address((ezb_extaddr_t *)auStack_18);
  return;
}

