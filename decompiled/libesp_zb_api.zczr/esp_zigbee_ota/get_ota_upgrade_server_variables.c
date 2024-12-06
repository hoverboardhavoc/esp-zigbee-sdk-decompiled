/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_ota.o -> get_ota_upgrade_server_variables
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 get_ota_upgrade_server_variables(void)

{
  int iVar1;
  
  iVar1 = zb_zcl_get_attr_desc_a(0x19,1,0xfff0);
  if (iVar1 == 0) {
    iVar1 = zb_assert(0x10000,0x38);
  }
  return *(undefined4 *)(iVar1 + 6);
}

