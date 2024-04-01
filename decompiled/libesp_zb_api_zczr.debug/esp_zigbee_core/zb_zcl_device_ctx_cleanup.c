/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> zb_zcl_device_ctx_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_device_ctx_cleanup(byte *param_1)

{
  int iVar1;
  void *__ptr;
  
  if (param_1 != (byte *)0x0) {
    if (*(int *)(param_1 + 1) != 0) {
      for (iVar1 = 0; iVar1 < (int)(uint)*param_1; iVar1 = iVar1 + 1) {
        __ptr = *(void **)(*(int *)(param_1 + 1) + iVar1 * 4);
        if (__ptr != (void *)0x0) {
          free(__ptr);
        }
      }
      free(*(void **)(param_1 + 1));
    }
    free(param_1);
    return;
  }
  return;
}

