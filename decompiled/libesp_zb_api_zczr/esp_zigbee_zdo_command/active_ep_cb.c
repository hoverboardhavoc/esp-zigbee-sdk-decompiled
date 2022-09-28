/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> active_ep_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void active_ep_cb(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  void *__ptr;
  int iVar4;
  
  pbVar3 = (byte *)zb_buf_begin_func();
  bVar1 = *pbVar3;
  __ptr = calloc(1,1);
  bVar2 = ZDO_INVALID_ENDPOINT;
  if (pbVar3[1] == 0) {
    __ptr = realloc(__ptr,(uint)pbVar3[4]);
    bVar2 = pbVar3[4];
    for (iVar4 = 0; iVar4 < (int)(uint)pbVar3[4]; iVar4 = iVar4 + 1) {
      *(byte *)((int)__ptr + iVar4) = pbVar3[iVar4 + 5];
    }
  }
  if (*(code **)(active_ep_user_cb + (uint)bVar1 * 4) != (code *)0x0) {
    (**(code **)(active_ep_user_cb + (uint)bVar1 * 4))(pbVar3[1],bVar2,__ptr);
    *(undefined4 *)(active_ep_user_cb + (uint)bVar1 * 4) = 0;
  }
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  free(__ptr);
  return;
}

