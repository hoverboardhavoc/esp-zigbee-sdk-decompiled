/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_zone_table_get_zone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_ias_ace_zone_table_ent_t *
ias_ace_zone_table_get_zone(ias_ace_zone_table_t *zone_table,uint8_t zone_id)

{
  ezb_zcl_ias_ace_zone_table_ent_t *peVar1;
  undefined3 in_register_0000202d;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if ((int)(uint)zone_table->table_size <= iVar2) {
      return (ezb_zcl_ias_ace_zone_table_ent_t *)0x0;
    }
    peVar1 = zone_table->zone_entries + iVar2;
    if ((peVar1->zone_type != 0xffff) &&
       ((uint)peVar1->zone_id == CONCAT31(in_register_0000202d,zone_id))) break;
    iVar2 = iVar2 + 1;
  }
  return peVar1;
}

