/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> device_scene_free_fields
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

