/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_internal_zcl_clean_attr_list_from_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_internal_zcl_clean_attr_list_from_set(void)

{
  int *__ptr;
  int iVar1;
  int *piVar2;
  
  __ptr = s_attr_list_set;
  for (piVar2 = s_attr_list_set; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[1]) {
    for (iVar1 = *piVar2; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
      free((void *)((uint)*(ushort *)(iVar1 + 6) | *(int *)(iVar1 + 8) << 0x10));
    }
  }
  while (__ptr != (int *)0x0) {
    piVar2 = (int *)__ptr[1];
    free(__ptr);
    __ptr = piVar2;
  }
  s_attr_list_set = (int *)0x0;
  return;
}

