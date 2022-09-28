/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_update_basic_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_list_update_basic_cluster(int param_1,int param_2,int param_3)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  short *__ptr;
  int local_30;
  uint3 uStack_28;
  undefined1 uStack_25;
  undefined2 uStack_24;
  
  piVar2 = (int *)malloc(0x14);
  sVar1 = *(short *)(*(int *)(param_2 + 0xc) + 8);
  iVar3 = zcl_get_attr_lists(param_2);
  local_30 = zcl_get_attr_count(param_2);
  if (param_1 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_L0,uVar4,"ESP_ZIGBEE_CLUSTER");
    uVar4 = 0x102;
  }
  else if (sVar1 == 0) {
    __ptr = *(short **)(param_1 + 0x10);
    while (__ptr != (short *)0x0) {
      if (*__ptr == 0) {
        local_30 = local_30 << 0x10;
        if (param_3 == 1) {
          puVar5 = &zb_zcl_basic_init_server;
        }
        else if (param_3 == 2) {
          puVar5 = &zb_zcl_basic_init_client;
        }
        else {
          puVar5 = (undefined *)0x0;
        }
        _uStack_28 = CONCAT13((char)puVar5,(uint3)(byte)param_3);
        uStack_24 = (undefined2)((uint)puVar5 >> 8);
        *piVar2 = local_30;
        piVar2[1] = iVar3;
        piVar2[2] = _uStack_28;
        *(undefined2 *)(piVar2 + 3) = uStack_24;
        *(undefined1 *)((int)piVar2 + 0xe) = 0;
        piVar2[4] = *(int *)(__ptr + 8);
        free(__ptr);
        *(int **)(param_1 + 0x10) = piVar2;
        return 0;
      }
      __ptr = *(short **)(__ptr + 8);
      if (__ptr == (short *)0x0) break;
      param_1 = *(int *)(param_1 + 0x10);
    }
    uVar4 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_CLUSTER",&_L0,uVar4,"ESP_ZIGBEE_CLUSTER");
    uVar4 = 0x105;
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC4,uVar4,"ESP_ZIGBEE_CLUSTER");
    uVar4 = 0x102;
  }
  return uVar4;
}

