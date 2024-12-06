/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_attribute.o -> esp_zb_internal_attribute_list_clone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_internal_attribute_list_clone(int *param_1,int param_2)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar1 = param_1;
  for (; param_2 != 0; param_2 = *(int *)(param_2 + 0xc)) {
    pvVar2 = malloc(0x10);
    *piVar1 = (int)pvVar2;
    if (pvVar2 == (void *)0x0) {
      iVar3 = 0x101;
      goto _L0;
    }
    iVar3 = esp_zb_internal_zcl_attr_clone(param_2);
    if (iVar3 != 0) break;
    *(undefined2 *)(*piVar1 + 10) = *(undefined2 *)(param_2 + 10);
    *(undefined4 *)(*piVar1 + 0xc) = 0;
    piVar1 = (int *)(*piVar1 + 0xc);
  }
  if (iVar3 != 0) {
_L0:
    esp_zb_internal_attribute_list_free(*param_1);
    *param_1 = 0;
  }
  return iVar3;
}

