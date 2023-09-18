/*
 * Last changed at upstream commit 6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * https://github.com/espressif/esp-zigbee-sdk/commit/6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * Upstream date: 2023-09-18 10:30:22 +0800
 * Upstream subject: esp-zigbee-sdk: add zigbee trace support and assert support(8c01f3c7)
 * Source: libesp_zb_api_zczr -> esp_zigbee_ota.o -> esp_zb_ota_file_load
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_zb_ota_file_load(byte *param_1)

{
  DAT_00010354 = 0;
  DAT_00010358 = 0;
  DAT_0001035c = 0;
  DAT_00010360 = 0;
  DAT_00010364 = 0;
  DAT_00010368 = 0;
  DAT_00010388 = *(int *)(param_1 + 0x10) + 0x38;
  DAT_0001038c = *(undefined4 *)(param_1 + 0x14);
  _ota_config = (uint)*param_1;
  DAT_00010350 = *(undefined4 *)(param_1 + 4);
  return;
}

