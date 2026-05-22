/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> zcl_cluster_desc_get_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

uint16_t zcl_cluster_desc_get_id(zcl_cluster_desc_t *cluster_desc)

{
  int iVar1;
  
  if (cluster_desc != (zcl_cluster_desc_t *)0x0) {
    return cluster_desc->cluster_id;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_desc.c",0x147,
                        "zcl_cluster_desc_get_id","cluster_desc");
  if (iVar1 != 0) {
    return (uint16_t)*(byte *)(iVar1 + 2);
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_desc.c",0x14d,
                        "zcl_cluster_desc_get_role","cluster_desc");
  if (iVar1 != 0) {
    return *(uint16_t *)(iVar1 + 4);
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_desc.c",0x153,
                "zcl_cluster_desc_get_manuf_code","cluster_desc");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

