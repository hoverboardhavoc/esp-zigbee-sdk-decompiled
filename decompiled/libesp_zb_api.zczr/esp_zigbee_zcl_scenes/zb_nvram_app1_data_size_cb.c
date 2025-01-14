/*
 * Last changed at upstream commit 5becf8b58fd0c6a13fec507be821364ad0ceba39
 * https://github.com/espressif/esp-zigbee-sdk/commit/5becf8b58fd0c6a13fec507be821364ad0ceba39
 * Upstream date: 2025-01-14 03:03:09 +0000
 * Upstream subject: esp-zigbee-sdk: (acad93d1)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> zb_nvram_app1_data_size_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort zb_nvram_app1_data_size_cb(void)

{
  short sVar1;
  undefined1 *puVar2;
  
  puVar2 = &esp_zb_zcl_scenes_table;
  sVar1 = 0;
  do {
    if (*(short *)(puVar2 + 2) != -1) {
      sVar1 = sVar1 + 8 + (ushort)(byte)puVar2[7];
    }
    puVar2 = puVar2 + 0xc;
  } while (puVar2 != (undefined1 *)0x1159c);
  return sVar1 + 0x11U & 0xfff0;
}

