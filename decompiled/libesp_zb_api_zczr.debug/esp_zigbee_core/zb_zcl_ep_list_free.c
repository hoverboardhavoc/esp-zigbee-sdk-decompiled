/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> zb_zcl_ep_list_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_ep_list_free(void *param_1)

{
  void *pvVar1;
  
  esp_zb_internal_zcl_clean_attr_list_from_set();
  esp_zb_internal_zcl_clean_cluster_list_from_set();
  while (param_1 != (void *)0x0) {
    pvVar1 = *(void **)((int)param_1 + 0x24);
    free(param_1);
    param_1 = pvVar1;
  }
  return;
}

