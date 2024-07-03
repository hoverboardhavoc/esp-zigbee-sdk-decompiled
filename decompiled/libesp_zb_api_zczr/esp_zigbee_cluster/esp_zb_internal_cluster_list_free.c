/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_internal_cluster_list_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_internal_cluster_list_free(void *param_1)

{
  void *pvVar1;
  
  for (pvVar1 = param_1; pvVar1 != (void *)0x0; pvVar1 = *(void **)((int)pvVar1 + 0x10)) {
    if (*(short *)((int)pvVar1 + 2) != 0) {
      zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_cluster.c",
                0x72);
    }
    if (*(int *)((int)pvVar1 + 4) != 0) {
      esp_zb_internal_attribute_list_free();
    }
  }
  while (param_1 != (void *)0x0) {
    pvVar1 = *(void **)((int)param_1 + 0x10);
    free(param_1);
    param_1 = pvVar1;
  }
  return;
}

