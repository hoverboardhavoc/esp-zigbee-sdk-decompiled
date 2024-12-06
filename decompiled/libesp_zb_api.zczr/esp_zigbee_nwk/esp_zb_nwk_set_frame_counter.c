/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_nwk.o -> esp_zb_nwk_set_frame_counter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zb_nwk_set_frame_counter(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zb_zdo_joined();
  if (iVar1 == 0) {
    uVar2 = 0;
    _g_zb = param_1;
  }
  else {
    uVar2 = 0x103;
  }
  return uVar2;
}

