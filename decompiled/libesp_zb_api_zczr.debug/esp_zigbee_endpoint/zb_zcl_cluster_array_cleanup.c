/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_endpoint.o -> zb_zcl_cluster_array_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_cluster_array_cleanup(byte *param_1)

{
  void *__ptr;
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != (byte *)0x0) {
    for (iVar3 = 0; iVar3 < (int)(uint)*param_1; iVar3 = iVar3 + 1) {
      iVar1 = *(int *)(param_1 + 4) + iVar3 * 0xf;
      if (*(int *)(iVar1 + 4) != 0) {
        for (iVar2 = 0; iVar2 < (int)(uint)*(ushort *)(iVar1 + 2); iVar2 = iVar2 + 1) {
          __ptr = *(void **)(*(int *)(iVar1 + 4) + iVar2 * 10 + 6);
          if (__ptr != (void *)0x0) {
            free(__ptr);
          }
        }
        free(*(void **)(iVar1 + 4));
      }
    }
    free(*(void **)(param_1 + 4));
    return;
  }
  return;
}

