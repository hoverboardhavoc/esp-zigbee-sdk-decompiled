/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_srv.o -> ezb_zcl_ota_upgrade_remove_ota_file
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_ota_upgrade_remove_ota_file(uint8_t ep_id,ezb_zcl_ota_file_handle_t ota_file)

{
  ota_upgrade_file_table_t *poVar1;
  ota_upgrade_file_t *poVar2;
  uint uVar3;
  
  poVar1 = ota_upgrade_get_file_table(ep_id);
  if (poVar1 != (ota_upgrade_file_table_t *)0x0) {
    uVar3 = 0;
    while ((uVar3 & 0xff) < (uint)poVar1->size) {
      poVar2 = poVar1->entry + uVar3;
      uVar3 = uVar3 + 1;
      if (poVar2 == (ota_upgrade_file_t *)ota_file) {
        memset(ota_file,0,0x4c);
        return;
      }
    }
  }
  return;
}

