/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> device_scenes_remove_entries_by_group
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char device_scenes_remove_entries_by_group(uint param_1,uint param_2)

{
  uint uVar1;
  byte *pbVar2;
  char cVar3;
  
  cVar3 = '\0';
  for (uVar1 = 0; uVar1 < esp_zb_zcl_scenes_table_capacity; uVar1 = uVar1 + 1 & 0xff) {
    pbVar2 = (byte *)(uVar1 * 0xc + esp_zb_zcl_scenes_table);
    if ((*pbVar2 == param_1) && (*(ushort *)(pbVar2 + 2) == param_2)) {
      device_scenes_table_record_free(uVar1);
      cVar3 = cVar3 + '\x01';
    }
  }
  return cVar3;
}

