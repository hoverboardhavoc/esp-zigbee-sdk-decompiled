/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_secur.o -> esp_zb_secur_multi_TC_standard_preconfigure_key_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_secur_multi_TC_standard_preconfigure_key_add(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = zb_aps_secur_multi_preconfigure_link_key_add(&g_zb,param_1);
  if (iVar1 != 0) {
    iVar1 = -1;
  }
  return iVar1;
}

