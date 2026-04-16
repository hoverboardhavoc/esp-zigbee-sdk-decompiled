/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_ace.o -> ezb_zcl_ias_ace_get_zone_table
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_ias_ace_zone_table_t ezb_zcl_ias_ace_get_zone_table(uint8_t ep_id)

{
  undefined3 in_register_00002029;
  ezb_zcl_ias_ace_zone_table_t pvVar1;
  
  pvVar1 = (ezb_zcl_ias_ace_zone_table_t)
           zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),0x501,1,0xeff1,0x131b);
  if (pvVar1 != (ezb_zcl_ias_ace_zone_table_t)0x0) {
    pvVar1 = *(ezb_zcl_ias_ace_zone_table_t *)((int)pvVar1 + 8);
  }
  return pvVar1;
}

