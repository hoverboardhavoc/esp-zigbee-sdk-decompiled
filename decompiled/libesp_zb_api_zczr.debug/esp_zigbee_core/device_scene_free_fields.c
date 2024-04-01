/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> device_scene_free_fields
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scene_free_fields(void *param_1)

{
  void *pvVar1;
  
  while (param_1 != (void *)0x0) {
    pvVar1 = *(void **)((int)param_1 + 8);
    free(*(void **)((int)param_1 + 4));
    free(param_1);
    param_1 = pvVar1;
  }
  return;
}

