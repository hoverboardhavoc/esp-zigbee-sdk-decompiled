/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_commissioning_desc.o -> ezb_zcl_touchlink_commissioning_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_cluster_desc_t
ezb_zcl_touchlink_commissioning_create_cluster_desc(void *cluster_cfg,uint8_t role_mask)

{
  ezb_zcl_cluster_desc_t pvVar1;
  undefined *puVar2;
  
  pvVar1 = (ezb_zcl_cluster_desc_t)zcl_create_cluster_desc(0x1000,0);
  if (pvVar1 != (ezb_zcl_cluster_desc_t)0x0) {
    if ((role_mask & 1) == 0) {
      puVar2 = &ezb_zcl_touchlink_commissioning_cluster_client_init;
    }
    else {
      puVar2 = &ezb_zcl_touchlink_commissioning_cluster_server_init;
    }
    *(undefined **)((int)pvVar1 + 8) = puVar2;
  }
  return pvVar1;
}

