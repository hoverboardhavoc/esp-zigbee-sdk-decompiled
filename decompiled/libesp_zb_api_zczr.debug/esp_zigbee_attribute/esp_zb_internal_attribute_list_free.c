/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_internal_attribute_list_free
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

