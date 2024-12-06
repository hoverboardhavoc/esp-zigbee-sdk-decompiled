/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_cluster.o -> esp_zb_internal_cluster_list_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_internal_cluster_list_free(void *param_1)

{
  void *pvVar1;
  
  for (pvVar1 = param_1; pvVar1 != (void *)0x0; pvVar1 = *(void **)((int)pvVar1 + 0x10)) {
    if (*(short *)((int)pvVar1 + 2) == 0) {
      if (*(int *)((int)pvVar1 + 4) != 0) {
        esp_zb_internal_attribute_list_free();
      }
    }
    else {
      zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_cluster.c",
                0x72);
    }
  }
  while (param_1 != (void *)0x0) {
    pvVar1 = *(void **)((int)param_1 + 0x10);
    free(param_1);
    param_1 = pvVar1;
  }
  return;
}

