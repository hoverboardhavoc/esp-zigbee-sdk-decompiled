/*
 * Last changed at upstream commit 5becf8b58fd0c6a13fec507be821364ad0ceba39
 * https://github.com/espressif/esp-zigbee-sdk/commit/5becf8b58fd0c6a13fec507be821364ad0ceba39
 * Upstream date: 2025-01-14 03:03:09 +0000
 * Upstream subject: esp-zigbee-sdk: (acad93d1)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> device_scenes_remove_entries_by_group
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
      if ((ushort)(&DAT_00012c7e)[uVar1 * 6] == param_2) {
        device_scenes_table_record_free(uVar1);
        cVar2 = cVar2 + '\x01';
      }
    }
  }
  return cVar2;
}

