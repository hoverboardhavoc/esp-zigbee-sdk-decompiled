/*
 * Last changed at upstream commit 62f83e9155a8a668183e90087b29cd6791297d4c
 * https://github.com/espressif/esp-zigbee-sdk/commit/62f83e9155a8a668183e90087b29cd6791297d4c
 * Upstream date: 2023-08-25 15:56:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.1(b4845e06)
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
      sVar2 = (ushort)(byte)(&DAT_0001467d)[iVar1 * 0xc] + sVar2 + 6;
    }
  }
  return sVar2;
}

