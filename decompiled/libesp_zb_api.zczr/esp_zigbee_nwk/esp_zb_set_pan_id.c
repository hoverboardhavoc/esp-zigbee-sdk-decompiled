/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_nwk.o -> esp_zb_set_pan_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_set_pan_id(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = zb_buf_get_out_func();
  zb_set_pan_id(param_1);
  zb_nwk_pib_set(uVar1,0xff,0x50,&g_zb,2,0);
  return;
}

