/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> esp_zb_zcl_scenes_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_table_init(void)

{
  esp_zb_zcl_scenes_table_set_size(0x10);
  zb_nvram_register_app1_read_cb(zb_nvram_app1_read_cb);
  zb_nvram_register_app1_write_cb(zb_nvram_app1_write_cb,0x10000);
  return;
}

