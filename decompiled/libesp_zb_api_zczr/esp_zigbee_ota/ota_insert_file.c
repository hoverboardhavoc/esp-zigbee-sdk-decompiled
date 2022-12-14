/*
 * Last changed at upstream commit dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * https://github.com/espressif/esp-zigbee-sdk/commit/dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * Upstream date: 2022-12-14 19:24:05 +0800
 * Upstream subject: examples:Add ota application example(986c075)
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
    *(undefined **)(puVar1 + 4) = &DAT_000102f0;
    *(undefined4 *)(puVar1 + 0xc) = DAT_000102ec;
    puVar1[8] = 1;
    zb_zcl_ota_upgrade_insert_file(param_1);
  }
  return;
}

