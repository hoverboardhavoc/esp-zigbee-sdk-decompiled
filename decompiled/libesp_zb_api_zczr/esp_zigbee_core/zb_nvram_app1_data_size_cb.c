/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_nvram_app1_data_size_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort zb_nvram_app1_data_size_cb(void)

{
  short sVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)&esp_zb_zcl_scenes_table;
  sVar1 = 0;
  do {
    if (*(short *)((int)puVar2 + 2) != -1) {
      sVar1 = sVar1 + 8 + (ushort)*(byte *)((int)puVar2 + 7);
    }
    puVar2 = puVar2 + 3;
  } while (puVar2 != &zcl_cli_resp_user_cb);
  return sVar1 + 0x11U & 0xfff0;
}

