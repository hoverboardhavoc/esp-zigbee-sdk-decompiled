/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_api_zczr -> esp_zigbee_ota.o -> esp_zb_ota_file_load
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_zb_ota_file_load(byte *param_1)

{
  DAT_000102f8 = 0;
  DAT_000102fc = 0;
  DAT_00010300 = 0;
  DAT_00010304 = 0;
  DAT_00010308 = 0;
  DAT_0001030c = 0;
  DAT_0001032c = *(int *)(param_1 + 0x10) + 0x38;
  DAT_00010330 = *(undefined4 *)(param_1 + 0x14);
  _ota_config = (uint)*param_1;
  DAT_000102f4 = *(undefined4 *)(param_1 + 4);
  return;
}

