/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_internal_zcl_clean_cluster_list_from_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_internal_zcl_clean_cluster_list_from_set(void)

{
  void *__ptr;
  int iVar1;
  void *pvVar2;
  undefined4 *__ptr_00;
  undefined4 *puVar3;
  
  __ptr_00 = s_cluster_list_set;
  for (puVar3 = s_cluster_list_set; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)puVar3[1]) {
    __ptr = (void *)*puVar3;
    for (iVar1 = 0; iVar1 < (int)(uint)*(ushort *)((int)__ptr + 2); iVar1 = iVar1 + 1) {
      free(*(void **)(*(int *)((int)__ptr + 4) + iVar1 * 10 + 6));
    }
    free(*(void **)((int)__ptr + 4));
    while (__ptr != (void *)0x0) {
      pvVar2 = *(void **)((int)__ptr + 0x10);
      free(__ptr);
      __ptr = pvVar2;
    }
  }
  while (__ptr_00 != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)__ptr_00[1];
    free(__ptr_00);
    __ptr_00 = puVar3;
  }
  s_cluster_list_set = (undefined4 *)0x0;
  return;
}

