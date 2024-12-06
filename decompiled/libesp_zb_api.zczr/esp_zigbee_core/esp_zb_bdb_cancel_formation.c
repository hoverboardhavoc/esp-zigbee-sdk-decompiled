/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_core.o -> esp_zb_bdb_cancel_formation
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_bdb_cancel_formation(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zb_buf_get_out_func();
  uVar2 = 0xffffffff;
  if (iVar1 != 0) {
    bdb_cancel_formation();
    uVar2 = 0;
  }
  return uVar2;
}

