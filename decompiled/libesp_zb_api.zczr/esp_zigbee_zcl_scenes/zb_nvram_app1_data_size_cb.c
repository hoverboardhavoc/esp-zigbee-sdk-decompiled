/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> zb_nvram_app1_data_size_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort zb_nvram_app1_data_size_cb(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  sVar1 = 0;
  iVar3 = s_nvram_app1_data;
  for (iVar2 = 0; iVar2 < (int)(uint)esp_zb_zcl_scenes_table_capacity; iVar2 = iVar2 + 1) {
    if ((iVar3 != 0) && (*(short *)(iVar3 + 2) != -1)) {
      sVar1 = sVar1 + 8 + (ushort)*(byte *)(iVar3 + 7);
    }
    iVar3 = iVar3 + 0xc;
  }
  return sVar1 + 0x11U & 0xfff0;
}

