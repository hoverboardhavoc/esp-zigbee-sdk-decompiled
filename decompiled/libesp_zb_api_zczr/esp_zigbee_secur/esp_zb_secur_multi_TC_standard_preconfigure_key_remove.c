/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_secur.o -> esp_zb_secur_multi_TC_standard_preconfigure_key_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_secur_multi_TC_standard_preconfigure_key_remove(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = zb_aps_secur_multi_preconfigure_link_key_remove(&g_zb,param_1);
  return -(uint)(iVar1 != 0);
}

