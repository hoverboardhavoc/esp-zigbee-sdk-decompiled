/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_commissioning_desc.o -> zcl_touchlink_commissioning_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_touchlink_commissioning_cluster_get_attr_properties
                    (uint16_t cluster_role,uint16_t attr_id,uint8_t *type,uint8_t *access)

{
  if (type != (uint8_t *)0x0) {
    if (access == (uint8_t *)0x0) {
      return 2;
    }
    if ((ushort)(cluster_role - 1) < 2) {
      return 6;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/touchlink_commissioning_desc.c"
                  ,0x19,"zcl_touchlink_commissioning_cluster_get_attr_properties",0x10000);
  }
  return 2;
}

