/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_nwk.o -> esp_zb_set_pan_id
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

