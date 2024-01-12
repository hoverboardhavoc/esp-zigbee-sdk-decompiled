/*
 * Last changed at upstream commit 9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * https://github.com/espressif/esp-zigbee-sdk/commit/9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * Upstream date: 2024-01-12 14:14:49 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.8(0e41638c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> device_scenes_remove_entries_by_group
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char device_scenes_remove_entries_by_group(uint param_1,uint param_2)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = '\0';
  for (uVar1 = 0; uVar1 < 0x10; uVar1 = uVar1 + 1 & 0xff) {
    if ((byte)(&esp_zb_zcl_scenes_table)[uVar1 * 0xc] == param_1) {
      if (*(ushort *)(&DAT_000176fa + uVar1 * 0xc) == param_2) {
        device_scenes_table_record_free(uVar1);
        cVar2 = cVar2 + '\x01';
      }
    }
  }
  return cVar2;
}

