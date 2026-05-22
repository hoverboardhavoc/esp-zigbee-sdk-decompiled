/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_reset(_Bool warm_start)

{
  undefined3 in_register_00002029;
  
  aps_retrans_purge(0xffff);
  aps_dup_table_clear();
  if (CONCAT31(in_register_00002029,warm_start) == 0) {
    aps_group_table_clear();
    aps_bind_table_clear();
    aps_secur_ctx_clear();
    return;
  }
  return;
}

