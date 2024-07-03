/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_internal_attribute_list_clone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_internal_attribute_list_clone(int *param_1,int param_2)

{
  undefined2 uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = param_1;
  while( true ) {
    if (param_2 == 0) {
      return 0;
    }
    pvVar2 = malloc(0x10);
    *piVar5 = (int)pvVar2;
    if (pvVar2 == (void *)0x0) break;
    iVar3 = esp_zb_internal_zcl_attr_clone(param_2);
    if (iVar3 != 0) goto _L0;
    iVar3 = *piVar5;
    uVar1 = *(undefined2 *)(param_2 + 10);
    *(undefined4 *)(iVar3 + 0xc) = 0;
    iVar4 = *piVar5;
    param_2 = *(int *)(param_2 + 0xc);
    *(undefined2 *)(iVar3 + 10) = uVar1;
    piVar5 = (int *)(iVar4 + 0xc);
  }
  iVar3 = 0x101;
_L0:
  esp_zb_internal_attribute_list_free(*param_1);
  *param_1 = 0;
  return iVar3;
}

