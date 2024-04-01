/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> device_scenes_remove_entries_by_group
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
      if ((ushort)(&DAT_00019ae6)[uVar1 * 6] == param_2) {
        device_scenes_table_record_free(uVar1);
        cVar2 = cVar2 + '\x01';
      }
    }
  }
  return cVar2;
}

