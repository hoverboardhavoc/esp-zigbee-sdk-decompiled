/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_core.o -> esp_err_to_zb_ret
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_err_to_zb_ret(int param_1)

{
  int iVar1;
  
  if (param_1 == 0x105) {
    iVar1 = -0x1c;
  }
  else if (param_1 < 0x106) {
    iVar1 = -0x16;
    if ((param_1 != 0x101) && (iVar1 = -6, param_1 != 0x104)) {
      return -(uint)(param_1 != 0);
    }
  }
  else {
    iVar1 = -0x1e;
    if ((param_1 != 0x107) && (iVar1 = -2, param_1 != 0x10c)) {
      return -1;
    }
  }
  return iVar1;
}

