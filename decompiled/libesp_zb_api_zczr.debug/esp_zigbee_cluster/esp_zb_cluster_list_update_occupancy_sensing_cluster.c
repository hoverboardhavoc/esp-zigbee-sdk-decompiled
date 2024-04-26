/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_cluster_list_update_occupancy_sensing_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_update_occupancy_sensing_cluster(int param_1,int param_2,byte param_3)

{
  short sVar1;
  short *psVar2;
  undefined2 extraout_a0;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uStack_38;
  uint uStack_30;
  
  sVar1 = *(short *)(*(int *)(param_2 + 0xc) + 10);
  iVar3 = esp_zb_cluster_list_check(0x406);
  if (iVar3 == 0) {
    psVar2 = *(short **)(param_1 + 0x10);
    while (psVar2 != (short *)0x0) {
      if (*psVar2 == sVar1) {
        puVar4 = (undefined4 *)malloc(0x14);
        if (puVar4 != (undefined4 *)0x0) {
          uVar5 = zcl_convert_attr_list_to_array(param_2);
          uStack_38 = CONCAT22(extraout_a0,0x406);
          uStack_30 = (uint)param_3;
          *puVar4 = uStack_38;
          puVar4[1] = uVar5;
          puVar4[2] = uStack_30;
          *(undefined2 *)(puVar4 + 3) = 0;
          *(undefined1 *)((int)puVar4 + 0xe) = 0;
          puVar4[4] = *(undefined4 *)(psVar2 + 8);
          *(undefined4 **)(param_1 + 0x10) = puVar4;
          zb_cluster_node_free(psVar2);
          return 0;
        }
        uVar5 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC24,uVar5,"ESP_ZIGBEE_CLUSTER",
                      "esp_zb_cluster_list_update_occupancy_sensing_cluster",0xca4,sVar1);
        return 0x101;
      }
      psVar2 = *(short **)(psVar2 + 8);
      if (psVar2 == (short *)0x0) {
        iVar3 = 0x105;
        break;
      }
      param_1 = *(int *)(param_1 + 0x10);
    }
    if (iVar3 != 0) {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC25,uVar5,"ESP_ZIGBEE_CLUSTER",
                    "esp_zb_cluster_list_update_occupancy_sensing_cluster",0xcbe,sVar1);
    }
  }
  else {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_L0,uVar5,"ESP_ZIGBEE_CLUSTER",
                  "esp_zb_cluster_list_update_occupancy_sensing_cluster",0xc9e);
  }
  return iVar3;
}

