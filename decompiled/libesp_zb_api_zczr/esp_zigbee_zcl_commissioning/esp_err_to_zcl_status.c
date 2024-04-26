/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_commissioning.o -> esp_err_to_zcl_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_err_to_zcl_status(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0x102) {
    uVar1 = 0x85;
  }
  else {
    if (param_1 < 0x103) {
      if (param_1 == 0) {
        return 0;
      }
      iVar2 = 0x101;
      uVar1 = 0x89;
    }
    else {
      if (param_1 == 0x106) {
        return 0x81;
      }
      iVar2 = 0x107;
      uVar1 = 0x94;
    }
    if (param_1 != iVar2) {
      return 1;
    }
  }
  return uVar1;
}

