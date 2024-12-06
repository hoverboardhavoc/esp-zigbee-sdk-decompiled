/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> data_model_adapter.o -> esp_zb_cluster_array_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_cluster_array_cleanup(byte *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 auStack_18 [2];
  int iStack_14;
  
  if (*(int *)(param_1 + 4) != 0) {
    for (iVar2 = 0; iVar2 < (int)(uint)*param_1; iVar2 = iVar2 + 1) {
      iVar3 = *(int *)(param_1 + 4) + iVar2 * 0xf;
      iVar1 = *(int *)(iVar3 + 4);
      if (iVar1 != 0) {
        auStack_18[0] = *(undefined2 *)(iVar3 + 2);
        iStack_14 = iVar1;
        esp_zb_attr_array_cleanup(auStack_18);
      }
    }
    free(*(void **)(param_1 + 4));
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}

