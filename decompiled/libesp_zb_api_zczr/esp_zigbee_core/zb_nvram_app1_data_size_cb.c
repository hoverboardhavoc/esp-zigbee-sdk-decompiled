/*
 * Last changed at upstream commit 3a2e620f73272cd71b1255d9566d72d6c662dd1c
 * https://github.com/espressif/esp-zigbee-sdk/commit/3a2e620f73272cd71b1255d9566d72d6c662dd1c
 * Upstream date: 2023-11-24 19:53:05 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.5(909d273b)
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
      sVar2 = (ushort)(byte)(&DAT_00016f3d)[iVar1 * 0xc] + sVar2 + 6;
    }
  }
  return sVar2;
}

