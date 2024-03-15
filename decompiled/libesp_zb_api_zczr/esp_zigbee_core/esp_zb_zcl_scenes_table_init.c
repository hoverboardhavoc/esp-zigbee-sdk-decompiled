/*
 * Last changed at upstream commit ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * https://github.com/espressif/esp-zigbee-sdk/commit/ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * Upstream date: 2024-03-15 18:43:30 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.1(aaf0078d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scenes_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_table_init(void)

{
  uint uVar1;
  
  zb_nvram_register_app1_read_cb(zb_nvram_app1_read_cb);
  zb_nvram_register_app1_write_cb(zb_nvram_app1_write_cb,0x10000);
  for (uVar1 = 0; uVar1 < 0x10; uVar1 = uVar1 + 1 & 0xff) {
    (&DAT_00018f0e)[uVar1 * 6] = 0xffff;
  }
  return;
}

