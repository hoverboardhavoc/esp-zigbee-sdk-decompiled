/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> esp_zb_zcl_scenes_table_clear_by_index
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_zcl_scenes_table_clear_by_index(uint param_1)

{
  int iVar1;
  
  if (param_1 < esp_zb_zcl_scenes_table_capacity) {
    if (*(short *)(esp_zb_zcl_scenes_table + param_1 * 0xc + 2) != -1) {
      device_scenes_table_record_free(param_1 & 0xff);
    }
    iVar1 = zb_nvram_write_dataset(9);
    return -(uint)(iVar1 != 0);
  }
  return 0x102;
}

