/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_nvram_app1_data_size_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

short zb_nvram_app1_data_size_cb(void)

{
  int iVar1;
  short sVar2;
  
  sVar2 = 0;
  for (iVar1 = 0; iVar1 < 10; iVar1 = iVar1 + 1) {
    if ((&esp_zb_zcl_scenes_table + iVar1 * 6 != (short *)0x0) &&
       ((&esp_zb_zcl_scenes_table)[iVar1 * 6] != -1)) {
      sVar2 = (ushort)(byte)(&DAT_000145c9)[iVar1 * 0xc] + sVar2 + 6;
    }
  }
  return sVar2;
}

