/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_internal_zcl_clean_attr_list_from_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_internal_zcl_clean_attr_list_from_set(void)

{
  void *__ptr;
  int iVar1;
  void *pvVar2;
  int *__ptr_00;
  int *piVar3;
  
  __ptr_00 = s_attr_list_set;
  for (piVar3 = s_attr_list_set; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[1]) {
    for (iVar1 = *piVar3; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
      free(*(void **)(iVar1 + 6));
    }
    __ptr = (void *)0x0;
    while (__ptr != (void *)0x0) {
      pvVar2 = *(void **)((int)__ptr + 0xc);
      free(__ptr);
      __ptr = pvVar2;
    }
  }
  while (__ptr_00 != (int *)0x0) {
    piVar3 = (int *)__ptr_00[1];
    free(__ptr_00);
    __ptr_00 = piVar3;
  }
  s_attr_list_set = (int *)0x0;
  return;
}

