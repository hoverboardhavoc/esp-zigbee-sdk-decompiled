/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_api.o -> ezb_zcl_get_attr_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_attr_desc_t
ezb_zcl_get_attr_desc
          (uint8_t ep_id,uint16_t cluster_id,uint8_t role,uint16_t attr_id,uint16_t manuf_code)

{
  undefined3 in_register_00002029;
  ezb_zcl_attr_desc_t pvVar1;
  
  pvVar1 = (ezb_zcl_attr_desc_t)zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id));
  return pvVar1;
}

