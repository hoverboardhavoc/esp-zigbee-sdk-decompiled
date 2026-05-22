/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> ezb_zcl_ota_upgrade_remove_ota_file
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_ota_upgrade_remove_ota_file(uint8_t ep_id,ezb_zcl_ota_file_handle_t ota_file)

{
  ota_upgrade_file_table_t *poVar1;
  uint uVar2;
  
  poVar1 = ota_upgrade_get_file_table(ep_id);
  if (poVar1 != (ota_upgrade_file_table_t *)0x0) {
    for (uVar2 = 0; uVar2 < poVar1->size; uVar2 = uVar2 + 1 & 0xff) {
      if (poVar1->entry + uVar2 == (ota_upgrade_file_t *)ota_file) {
        memset(poVar1->entry + uVar2,0,0x4c);
        return;
      }
    }
  }
  return;
}

