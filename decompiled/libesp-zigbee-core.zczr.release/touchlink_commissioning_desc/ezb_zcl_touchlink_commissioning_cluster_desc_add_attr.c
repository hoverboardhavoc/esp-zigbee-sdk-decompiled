/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_commissioning_desc.o -> ezb_zcl_touchlink_commissioning_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_touchlink_commissioning_cluster_desc_add_attr
                    (ezb_zcl_cluster_desc_t cluster_desc,uint16_t attr_id,void *value)

{
  if (cluster_desc != (ezb_zcl_cluster_desc_t)0x0) {
                    /* WARNING: Load size is inaccurate */
    if (*cluster_desc != 0x1000) {
      return 2;
    }
    if ((ushort)(*(byte *)((int)cluster_desc + 2) - 1) < 2) {
      return 6;
    }
    __assert_func(0,0,0,0);
  }
  return 2;
}

