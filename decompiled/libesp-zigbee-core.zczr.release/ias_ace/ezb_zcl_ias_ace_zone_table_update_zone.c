/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_ace.o -> ezb_zcl_ias_ace_zone_table_update_zone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_ias_ace_zone_table_update_zone
                    (ezb_zcl_ias_ace_zone_table_t table,
                    ezb_zcl_ias_ace_zone_table_ent_t *update_entry)

{
  int iVar1;
  ezb_zcl_ias_ace_zone_table_ent_t *entry;
  ezb_err_t eVar2;
  
  if (table != (ezb_zcl_ias_ace_zone_table_t)0x0) {
    eVar2 = 2;
    if ((((update_entry != (ezb_zcl_ias_ace_zone_table_ent_t *)0x0) &&
         (update_entry->zone_id != 0xff)) && (update_entry->zone_type != 0xffff)) &&
       ((iVar1 = *(int *)&(update_entry->zone_address).field_0,
        *(int *)((int)&(update_entry->zone_address).field_0 + 4) + 1U != (uint)(iVar1 == 0) ||
        (eVar2 = 2, iVar1 - 1U < 0xfffffffe)))) {
      entry = ias_ace_zone_table_get_zone((ias_ace_zone_table_t *)table,update_entry->zone_id);
      eVar2 = 2;
      if (entry != (ezb_zcl_ias_ace_zone_table_ent_t *)0x0) {
        memcpy(entry,update_entry,0x1e);
        zone_table_remove_stored_zone(*(uint8_t *)((int)table + 5),update_entry->zone_id);
        zone_table_store_zone(*(uint8_t *)((int)table + 5),entry);
        eVar2 = 0;
      }
    }
    return eVar2;
  }
  return 2;
}

