/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_ota.o -> zb_zcl_get_ota_upgrade_header_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_zcl_get_ota_upgrade_header_size(uint param_1)

{
  int iVar1;
  
  if ((param_1 & 1) == 0) {
    iVar1 = 0x38;
  }
  else {
    iVar1 = 0x39;
  }
  if ((param_1 & 2) != 0) {
    iVar1 = iVar1 + 8;
  }
  if ((param_1 & 4) != 0) {
    iVar1 = iVar1 + 4;
  }
  return iVar1;
}

