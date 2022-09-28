/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_basic_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_list_add_basic_cluster(int param_1,int param_2,uint param_3)

{
  short *psVar1;
  short *psVar2;
  ushort uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined *puVar7;
  int local_30;
  uint3 uStack_28;
  undefined1 uStack_25;
  undefined2 uStack_24;
  
  piVar4 = (int *)malloc(0x14);
  if (param_1 == 0) {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_L0,uVar6,"ESP_ZIGBEE_CLUSTER");
    uVar6 = 0x102;
  }
  else if (*(short *)(*(int *)(param_2 + 0xc) + 8) == 0) {
    psVar1 = *(short **)(param_1 + 0x10);
    do {
      psVar2 = psVar1;
      if (psVar2 == (short *)0x0) break;
      if (*psVar2 == 0 && *(byte *)(psVar2 + 4) == param_3) {
        uVar6 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC5,uVar6,"ESP_ZIGBEE_CLUSTER",0);
        return 0x102;
      }
      psVar1 = *(short **)(psVar2 + 8);
    } while (*(short **)(psVar2 + 8) != (short *)0x0);
    iVar5 = zcl_get_attr_lists(param_2);
    uVar3 = zcl_get_attr_count(param_2);
    local_30 = (uint)uVar3 << 0x10;
    if (param_3 == 1) {
      puVar7 = &zb_zcl_basic_init_server;
    }
    else if (param_3 == 2) {
      puVar7 = &zb_zcl_basic_init_client;
    }
    else {
      puVar7 = (undefined *)0x0;
    }
    _uStack_28 = CONCAT13((char)puVar7,(uint3)(byte)param_3);
    uStack_24 = (undefined2)((uint)puVar7 >> 8);
    *piVar4 = local_30;
    piVar4[1] = iVar5;
    piVar4[2] = _uStack_28;
    *(undefined2 *)(piVar4 + 3) = uStack_24;
    *(undefined1 *)((int)piVar4 + 0xe) = 0;
    piVar4[4] = 0;
    if (psVar2 == (short *)0x0) {
      *(int **)(param_1 + 0x10) = piVar4;
      uVar6 = 0;
    }
    else {
      *(int **)(psVar2 + 8) = piVar4;
      uVar6 = 0;
    }
  }
  else {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC4,uVar6,"ESP_ZIGBEE_CLUSTER");
    uVar6 = 0x102;
  }
  return uVar6;
}

