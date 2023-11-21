/*
 * Last changed at upstream commit 6663e9a47e70aeb89bdde3d1385b4fa8af6242fa
 * https://github.com/espressif/esp-zigbee-sdk/commit/6663e9a47e70aeb89bdde3d1385b4fa8af6242fa
 * Upstream date: 2023-11-21 18:28:11 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.4(be3a8a97)
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
      sVar2 = (ushort)(byte)(&DAT_00016f39)[iVar1 * 0xc] + sVar2 + 6;
    }
  }
  return sVar2;
}

