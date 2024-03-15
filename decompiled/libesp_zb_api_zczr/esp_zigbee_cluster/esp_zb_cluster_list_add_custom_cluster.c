/*
 * Last changed at upstream commit ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * https://github.com/espressif/esp-zigbee-sdk/commit/ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * Upstream date: 2024-03-15 18:43:30 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.1(aaf0078d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_custom_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_add_custom_cluster(int param_1,int param_2,uint param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 extraout_a0;
  undefined4 *__ptr;
  int iVar3;
  undefined4 uVar4;
  undefined4 uStack_3c;
  uint uStack_34;
  int iStack_24;
  
  __ptr = (undefined4 *)malloc(0x14);
  iStack_24 = 0;
  iVar3 = esp_zb_cluster_list_get_tail(param_1,param_2,0x8000,param_3,&iStack_24);
  iVar2 = iStack_24;
  uVar1 = *(undefined2 *)(*(int *)(param_2 + 0xc) + 10);
  if (iStack_24 == 0) {
    uVar4 = zcl_convert_attr_list_to_array(param_2);
    uStack_3c = CONCAT22(extraout_a0,uVar1);
    uStack_34 = param_3 & 0xff;
    *__ptr = uStack_3c;
    __ptr[1] = uVar4;
    __ptr[2] = uStack_34;
    *(undefined2 *)(__ptr + 3) = 0;
    *(undefined1 *)((int)__ptr + 0xe) = 0;
    __ptr[4] = 0;
    iStack_24 = iVar2;
    if (iVar3 == 0) {
      *(undefined4 **)(param_1 + 0x10) = __ptr;
    }
    else {
      *(undefined4 **)(iVar3 + 0x10) = __ptr;
    }
  }
  else {
    free(__ptr);
  }
  return iStack_24;
}

