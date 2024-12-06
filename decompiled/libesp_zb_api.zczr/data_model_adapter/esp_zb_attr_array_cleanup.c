/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> data_model_adapter.o -> esp_zb_attr_array_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_attr_array_cleanup(ushort *param_1)

{
  void *__ptr;
  int iVar1;
  
  if (*(int *)(param_1 + 2) != 0) {
    for (iVar1 = 0; iVar1 < (int)(uint)*param_1; iVar1 = iVar1 + 1) {
      __ptr = *(void **)((int)*(void **)(param_1 + 2) + iVar1 * 10 + 6);
      if (__ptr != (void *)0x0) {
        free(__ptr);
      }
    }
    free(*(void **)(param_1 + 2));
    param_1[2] = 0;
    param_1[3] = 0;
  }
  *param_1 = 0;
  return;
}

