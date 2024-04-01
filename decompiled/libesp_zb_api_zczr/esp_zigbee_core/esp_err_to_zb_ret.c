/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_err_to_zb_ret
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

