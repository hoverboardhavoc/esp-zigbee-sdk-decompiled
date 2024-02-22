/*
 * Last changed at upstream commit a67793c7af0a02d983345915fecc5d8fce7a0945
 * https://github.com/espressif/esp-zigbee-sdk/commit/a67793c7af0a02d983345915fecc5d8fce7a0945
 * Upstream date: 2024-02-22 20:57:09 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.2(af7a8c4d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_nvram_app1_data_size_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort zb_nvram_app1_data_size_cb(void)

{
  int iVar1;
  short sVar2;
  
  sVar2 = 0;
  for (iVar1 = 0; iVar1 < 0x10; iVar1 = iVar1 + 1) {
    if ((iVar1 * 0xc != -0x18e5c) && ((&DAT_00018e5e)[iVar1 * 6] != -1)) {
      sVar2 = (ushort)(byte)(&DAT_00018e63)[iVar1 * 0xc] + sVar2 + 8;
    }
  }
  return sVar2 + 0x11U & 0xfff0;
}

