/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ezb_zcl_ias_ace_zone_table_remove_zone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_ias_ace_zone_table_remove_zone(ezb_zcl_ias_ace_zone_table_t table,uint8_t zone_id)

{
  ezb_zcl_ias_ace_zone_table_ent_t *__s;
  ezb_err_t eVar1;
  undefined3 in_register_0000202d;
  
  if (table == (ezb_zcl_ias_ace_zone_table_t)0x0) {
    eVar1 = 2;
  }
  else if (CONCAT31(in_register_0000202d,zone_id) == 0xff) {
    eVar1 = 2;
  }
  else {
    __s = ias_ace_zone_table_get_zone((ias_ace_zone_table_t *)table,zone_id);
    if (__s == (ezb_zcl_ias_ace_zone_table_ent_t *)0x0) {
      eVar1 = 2;
    }
    else {
      zone_table_remove_stored_zone(*(uint8_t *)((int)table + 5),zone_id);
      memset(__s,0,0x1e);
      (__s->zone_address).field_0.u8[0] = 0xff;
      (__s->zone_address).field_0.u8[1] = 0xff;
      (__s->zone_address).field_0.u8[2] = 0xff;
      (__s->zone_address).field_0.u8[3] = 0xff;
      (__s->zone_address).field_0.u8[4] = 0xff;
      (__s->zone_address).field_0.u8[5] = 0xff;
      (__s->zone_address).field_0.u8[6] = 0xff;
      (__s->zone_address).field_0.u8[7] = 0xff;
      __s->zone_type = 0xffff;
      eVar1 = 0;
    }
  }
  return eVar1;
}

