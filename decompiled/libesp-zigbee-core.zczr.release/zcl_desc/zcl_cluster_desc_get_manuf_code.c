/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zcl_desc.o -> zcl_cluster_desc_get_manuf_code
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t zcl_cluster_desc_get_manuf_code(zcl_cluster_desc_t *cluster_desc)

{
  if (cluster_desc == (zcl_cluster_desc_t *)0x0) {
    cluster_desc = (zcl_cluster_desc_t *)__assert_func(0,0,0);
  }
  return cluster_desc->manuf_code;
}

