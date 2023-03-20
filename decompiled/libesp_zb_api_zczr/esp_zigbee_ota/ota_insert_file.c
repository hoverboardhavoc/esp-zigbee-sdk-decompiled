/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_api_zczr -> esp_zigbee_ota.o -> ota_insert_file
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ota_insert_file(int param_1)

{
  undefined1 *puVar1;
  
  if (param_1 == 0) {
    zb_buf_get_out_delayed_func(ota_insert_file);
  }
  else {
    puVar1 = (undefined1 *)zb_buf_get_tail_func(0x10);
    *puVar1 = ota_config;
    puVar1[1] = 0;
    *(undefined1 **)(puVar1 + 4) = &ota_config;
    *(undefined4 *)(puVar1 + 0xc) = DAT_000102f4;
    puVar1[8] = 1;
    zb_zcl_ota_upgrade_insert_file(param_1);
  }
  return;
}

