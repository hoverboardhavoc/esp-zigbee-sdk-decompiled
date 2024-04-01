/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_internal_zcl_clean_cluster_list_from_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_internal_zcl_clean_cluster_list_from_set(void)

{
  void *__ptr;
  void *pvVar1;
  int *piVar2;
  int *__ptr_00;
  int iVar3;
  
  __ptr_00 = s_cluster_list_set;
  for (piVar2 = s_cluster_list_set; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[1]) {
    __ptr = (void *)*piVar2;
    for (iVar3 = 0; iVar3 < (int)(uint)*(ushort *)((int)__ptr + 2); iVar3 = iVar3 + 1) {
      free(*(void **)((int)*(void **)((int)__ptr + 4) + iVar3 * 10 + 6));
    }
    free(*(void **)((int)__ptr + 4));
    do {
      pvVar1 = *(void **)((int)__ptr + 0x10);
      free(__ptr);
      __ptr = pvVar1;
    } while (pvVar1 != (void *)0x0);
  }
  while (__ptr_00 != (int *)0x0) {
    piVar2 = (int *)__ptr_00[1];
    free(__ptr_00);
    __ptr_00 = piVar2;
  }
  s_cluster_list_set = (int *)0x0;
  return;
}

