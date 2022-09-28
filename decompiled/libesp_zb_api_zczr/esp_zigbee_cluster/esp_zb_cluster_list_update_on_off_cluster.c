/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_update_on_off_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_list_update_on_off_cluster(int param_1,int param_2,int param_3)

{
  short sVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined *puVar5;
  short *__ptr;
  undefined4 local_30;
  uint3 uStack_28;
  undefined1 uStack_25;
  undefined2 uStack_24;
  
  puVar3 = (undefined4 *)malloc(0x14);
  sVar1 = *(short *)(*(int *)(param_2 + 0xc) + 8);
  uVar4 = zcl_get_attr_lists(param_2);
  uVar2 = zcl_get_attr_count(param_2);
  if (param_1 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_L0,uVar4,"ESP_ZIGBEE_CLUSTER");
    uVar4 = 0x102;
  }
  else if (sVar1 == 6) {
    __ptr = *(short **)(param_1 + 0x10);
    while (__ptr != (short *)0x0) {
      if (*__ptr == 6) {
        local_30 = CONCAT22(uVar2,6);
        if (param_3 == 1) {
          puVar5 = &zb_zcl_on_off_init_server;
        }
        else if (param_3 == 2) {
          puVar5 = &zb_zcl_on_off_init_client;
        }
        else {
          puVar5 = (undefined *)0x0;
        }
        _uStack_28 = CONCAT13((char)puVar5,(uint3)(byte)param_3);
        uStack_24 = (undefined2)((uint)puVar5 >> 8);
        *puVar3 = local_30;
        puVar3[1] = uVar4;
        puVar3[2] = _uStack_28;
        *(undefined2 *)(puVar3 + 3) = uStack_24;
        *(undefined1 *)((int)puVar3 + 0xe) = 0;
        puVar3[4] = *(undefined4 *)(__ptr + 8);
        free(__ptr);
        *(undefined4 **)(param_1 + 0x10) = puVar3;
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
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_L0,uVar4,"ESP_ZIGBEE_CLUSTER");
    uVar4 = 0x102;
  }
  return uVar4;
}

