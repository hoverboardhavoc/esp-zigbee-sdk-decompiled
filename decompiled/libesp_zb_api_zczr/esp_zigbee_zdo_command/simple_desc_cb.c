/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> simple_desc_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void simple_desc_cb(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *__ptr;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  pbVar3 = (byte *)zb_buf_begin_func();
  bVar1 = *pbVar3;
  __ptr = (byte *)malloc(0xc);
  if (pbVar3[1] == 0) {
    uVar6 = (uint)pbVar3[0xb] + (uint)pbVar3[0xc] & 0xff;
    __ptr = (byte *)realloc(__ptr,(uVar6 + 4) * 2);
    bVar2 = pbVar3[9];
    __ptr[3] = pbVar3[8];
    __ptr[4] = bVar2;
    __ptr[5] = __ptr[5] & 0xf0 | pbVar3[10] & 0xf;
    __ptr[6] = pbVar3[0xb];
    __ptr[7] = pbVar3[0xc];
    bVar2 = pbVar3[7];
    __ptr[1] = pbVar3[6];
    __ptr[2] = bVar2;
    *__ptr = pbVar3[5];
    for (iVar4 = 0; iVar4 < (int)uVar6; iVar4 = iVar4 + 1) {
      iVar5 = iVar4 * 2;
      bVar2 = pbVar3[iVar5 + 0xe];
      __ptr[iVar5 + 8] = pbVar3[iVar5 + 0xd];
      __ptr[iVar5 + 9] = bVar2;
    }
  }
  if (*(code **)(simple_desc_user_cb + (uint)bVar1 * 4) != (code *)0x0) {
    (**(code **)(simple_desc_user_cb + (uint)bVar1 * 4))(pbVar3[1],__ptr);
    *(undefined4 *)(simple_desc_user_cb + (uint)bVar1 * 4) = 0;
  }
  free(__ptr);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

