/*
 * Last changed at upstream commit 7abab98979b3ea95f88c7b3687103b07986e5dd5
 * https://github.com/espressif/esp-zigbee-sdk/commit/7abab98979b3ea95f88c7b3687103b07986e5dd5
 * Upstream date: 2022-11-14 17:26:16 +0800
 * Upstream subject: examples: support rename esp32h2 to esp32h4
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_groups_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_list_add_groups_cluster(int param_1,int param_2,uint param_3)

{
  short *psVar1;
  short *psVar2;
  undefined2 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined4 local_30;
  uint3 uStack_28;
  undefined1 uStack_25;
  undefined2 uStack_24;
  
  puVar4 = (undefined4 *)malloc(0x14);
  if (param_1 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_L0,uVar5,"ESP_ZIGBEE_CLUSTER");
    uVar5 = 0x102;
  }
  else if (*(short *)(*(int *)(param_2 + 0xc) + 10) == 4) {
    psVar1 = *(short **)(param_1 + 0x10);
    do {
      psVar2 = psVar1;
      if (psVar2 == (short *)0x0) break;
      if (*psVar2 == 4 && *(byte *)(psVar2 + 4) == param_3) {
        uVar5 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC5,uVar5,"ESP_ZIGBEE_CLUSTER",4);
        return 0x102;
      }
      psVar1 = *(short **)(psVar2 + 8);
    } while (*(short **)(psVar2 + 8) != (short *)0x0);
    uVar5 = zcl_get_attr_lists(param_2);
    uVar3 = zcl_get_attr_count(param_2);
    local_30 = CONCAT22(uVar3,4);
    if (param_3 == 1) {
      puVar6 = &zb_zcl_groups_init_server;
    }
    else if (param_3 == 2) {
      puVar6 = &zb_zcl_groups_init_client;
    }
    else {
      puVar6 = (undefined *)0x0;
    }
    _uStack_28 = CONCAT13((char)puVar6,(uint3)(byte)param_3);
    uStack_24 = (undefined2)((uint)puVar6 >> 8);
    *puVar4 = local_30;
    puVar4[1] = uVar5;
    puVar4[2] = _uStack_28;
    *(undefined2 *)(puVar4 + 3) = uStack_24;
    *(undefined1 *)((int)puVar4 + 0xe) = 0;
    puVar4[4] = 0;
    if (psVar2 == (short *)0x0) {
      *(undefined4 **)(param_1 + 0x10) = puVar4;
      uVar5 = 0;
    }
    else {
      *(undefined4 **)(psVar2 + 8) = puVar4;
      uVar5 = 0;
    }
  }
  else {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC7,uVar5,"ESP_ZIGBEE_CLUSTER");
    uVar5 = 0x102;
  }
  return uVar5;
}

