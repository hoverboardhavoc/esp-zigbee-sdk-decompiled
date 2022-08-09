/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_core.o -> zcl_get_ep_lists
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * zcl_get_ep_lists(int param_1)

{
  undefined1 *puVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  size_t __nmemb;
  
  __nmemb = 0;
  iVar4 = param_1;
  while (iVar4 = *(int *)(iVar4 + 0x24), iVar4 != 0) {
    __nmemb = __nmemb + 1 & 0xff;
  }
  puVar1 = (undefined1 *)malloc(5);
  *puVar1 = (char)__nmemb;
  pvVar2 = calloc(__nmemb,4);
  puVar1[1] = (char)pvVar2;
  puVar1[2] = (char)((uint)pvVar2 >> 8);
  puVar1[3] = (char)((uint)pvVar2 >> 0x10);
  puVar1[4] = (char)((uint)pvVar2 >> 0x18);
  uVar3 = 0;
  while (param_1 = *(int *)(param_1 + 0x24), param_1 != 0) {
    *(int *)(*(int *)(puVar1 + 1) + uVar3 * 4) = param_1;
    uVar3 = uVar3 + 1 & 0xff;
  }
  return puVar1;
}

