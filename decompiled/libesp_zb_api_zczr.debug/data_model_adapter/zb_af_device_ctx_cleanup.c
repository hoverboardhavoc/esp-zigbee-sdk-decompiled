/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> data_model_adapter.o -> zb_af_device_ctx_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_af_device_ctx_cleanup(byte *param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  uint uStack_18;
  undefined4 uStack_14;
  
  if (param_1 != (byte *)0x0) {
    if (*(int *)(param_1 + 1) != 0) {
      for (iVar2 = 0; iVar2 < (int)(uint)*param_1; iVar2 = iVar2 + 1) {
        iVar3 = iVar2 * 4;
        if (*(int *)(*(int *)(param_1 + 1) + iVar3) != 0) {
          uStack_18 = (uint)*(byte *)(*(int *)(*(int *)(param_1 + 1) + iVar3) + 0x10);
          uStack_14 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 1) + iVar3) + 0x11);
          esp_zb_cluster_array_cleanup(&uStack_18);
          pvVar1 = *(void **)(*(int *)(*(int *)(param_1 + 1) + iVar3) + 0x1b);
          if (pvVar1 != (void *)0x0) {
            free(pvVar1);
          }
          pvVar1 = *(void **)(*(int *)(*(int *)(param_1 + 1) + iVar3) + 0x20);
          if (pvVar1 != (void *)0x0) {
            free(pvVar1);
          }
          free(*(void **)(*(int *)(param_1 + 1) + iVar3));
        }
      }
      free(*(void **)(param_1 + 1));
    }
    free(param_1);
  }
  return;
}

