/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_api.o -> ezb_zcl_cluster_remove_attr_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_attr_desc_t
ezb_zcl_cluster_remove_attr_desc
          (ezb_zcl_cluster_desc_t cluster_desc,uint16_t attr_id,uint16_t manuf_code)

{
  ezb_zcl_attr_desc_t pvVar1;
  
  pvVar1 = (ezb_zcl_attr_desc_t)zcl_cluster_remove_attr_desc();
  return pvVar1;
}

