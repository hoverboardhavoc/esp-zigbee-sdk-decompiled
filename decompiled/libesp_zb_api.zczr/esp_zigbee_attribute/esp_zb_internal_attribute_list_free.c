/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_attribute.o -> esp_zb_internal_attribute_list_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_internal_attribute_list_free(void *param_1)

{
  void *pvVar1;
  
  for (pvVar1 = param_1; pvVar1 != (void *)0x0; pvVar1 = *(void **)((int)pvVar1 + 0xc)) {
    if (*(void **)((int)pvVar1 + 6) != (void *)0x0) {
      free(*(void **)((int)pvVar1 + 6));
      *(undefined2 *)((int)pvVar1 + 6) = 0;
      *(undefined2 *)((int)pvVar1 + 8) = 0;
    }
  }
  while (param_1 != (void *)0x0) {
    pvVar1 = *(void **)((int)param_1 + 0xc);
    free(param_1);
    param_1 = pvVar1;
  }
  return;
}

