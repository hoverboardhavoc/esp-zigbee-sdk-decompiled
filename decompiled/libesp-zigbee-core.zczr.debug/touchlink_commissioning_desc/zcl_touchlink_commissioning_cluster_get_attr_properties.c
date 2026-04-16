/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/touchlink_commissioning_desc.c",0x19,
                  "zcl_touchlink_commissioning_cluster_get_attr_properties",0x10000);
  }
  return 2;
}

