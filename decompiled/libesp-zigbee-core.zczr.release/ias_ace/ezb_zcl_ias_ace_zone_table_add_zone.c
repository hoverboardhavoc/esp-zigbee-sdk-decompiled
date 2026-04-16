/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_ace.o -> ezb_zcl_ias_ace_zone_table_add_zone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_ias_ace_zone_table_add_zone
                    (ezb_zcl_ias_ace_zone_table_t table,ezb_zcl_ias_ace_zone_table_ent_t *new_entry)

{
  ezb_zcl_ias_ace_zone_table_ent_t *peVar1;
  int iVar2;
  void *__dest;
  
  if (table == (ezb_zcl_ias_ace_zone_table_t)0x0) {
    return 2;
  }
  if ((((new_entry != (ezb_zcl_ias_ace_zone_table_ent_t *)0x0) && (new_entry->zone_id != 0xff)) &&
      (new_entry->zone_type != 0xffff)) &&
     (((iVar2 = *(int *)&(new_entry->zone_address).field_0,
       *(int *)((int)&(new_entry->zone_address).field_0 + 4) + 1U != (uint)(iVar2 == 0) ||
       (iVar2 - 1U < 0xfffffffe)) &&
      (peVar1 = ias_ace_zone_table_get_zone((ias_ace_zone_table_t *)table,new_entry->zone_id),
      peVar1 == (ezb_zcl_ias_ace_zone_table_ent_t *)0x0)))) {
    for (iVar2 = 0; iVar2 < (int)(uint)*(byte *)((int)table + 4); iVar2 = iVar2 + 1) {
                    /* WARNING: Load size is inaccurate */
      __dest = (void *)(*table + iVar2 * 0x1e);
      if (*(short *)((int)__dest + 2) == -1) {
        peVar1 = (ezb_zcl_ias_ace_zone_table_ent_t *)memcpy(__dest,new_entry,0x1e);
        zone_table_store_zone(*(uint8_t *)((int)table + 5),peVar1);
        return 0;
      }
    }
  }
  return 2;
}

