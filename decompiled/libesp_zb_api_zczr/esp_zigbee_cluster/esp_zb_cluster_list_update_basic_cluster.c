/*
 * Last changed at upstream commit 6a9e3c6fdc96f7e7c0611d7b4a7e17141165ca31
 * https://github.com/espressif/esp-zigbee-sdk/commit/6a9e3c6fdc96f7e7c0611d7b4a7e17141165ca31
 * Upstream date: 2023-04-06 16:02:34 +0800
 * Upstream subject: example: support single C6 gateway example and other API support(a1884f9)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_update_basic_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_update_basic_cluster(int param_1,int param_2,int param_3)

{
  short sVar1;
  int *__ptr;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  short *__ptr_00;
  int local_30;
  uint3 uStack_28;
  undefined1 uStack_25;
  undefined2 uStack_24;
  
  __ptr = (int *)malloc(0x14);
  iVar2 = esp_zb_cluster_list_check(param_1,param_2,0);
  if (iVar2 == 0) {
    sVar1 = *(short *)(*(int *)(param_2 + 0xc) + 10);
    iVar2 = zcl_get_attr_lists(param_2);
    local_30 = zcl_get_attr_count(param_2);
    __ptr_00 = *(short **)(param_1 + 0x10);
    while (__ptr_00 != (short *)0x0) {
      if (*__ptr_00 == sVar1) {
        local_30 = local_30 << 0x10;
        if (param_3 == 1) {
          puVar4 = &zb_zcl_basic_init_server;
        }
        else if (param_3 == 2) {
          puVar4 = &zb_zcl_basic_init_client;
        }
        else {
          puVar4 = (undefined *)0x0;
        }
        _uStack_28 = CONCAT13((char)puVar4,(uint3)(byte)param_3);
        uStack_24 = (undefined2)((uint)puVar4 >> 8);
        *__ptr = local_30;
        __ptr[1] = iVar2;
        __ptr[2] = _uStack_28;
        *(undefined2 *)(__ptr + 3) = uStack_24;
        *(undefined1 *)((int)__ptr + 0xe) = 0;
        __ptr[4] = *(int *)(__ptr_00 + 8);
        free(__ptr_00);
        *(int **)(param_1 + 0x10) = __ptr;
        return 0;
      }
      __ptr_00 = *(short **)(__ptr_00 + 8);
      if (__ptr_00 == (short *)0x0) break;
      param_1 = *(int *)(param_1 + 0x10);
    }
    uVar3 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_CLUSTER",&_LC11,uVar3,"ESP_ZIGBEE_CLUSTER");
    iVar2 = 0x105;
  }
  else {
    free(__ptr);
  }
  return iVar2;
}

