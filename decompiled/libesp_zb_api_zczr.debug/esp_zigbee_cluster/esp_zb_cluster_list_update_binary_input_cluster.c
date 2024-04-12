/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_cluster_list_update_binary_input_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_update_binary_input_cluster(int param_1,int param_2,int param_3)

{
  short sVar1;
  short *psVar2;
  undefined2 extraout_a0;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined4 uStack_38;
  uint3 uStack_30;
  undefined1 uStack_2d;
  undefined2 uStack_2c;
  
  sVar1 = *(short *)(*(int *)(param_2 + 0xc) + 10);
  iVar3 = esp_zb_cluster_list_check(0xf);
  if (iVar3 == 0) {
    psVar2 = *(short **)(param_1 + 0x10);
    while (psVar2 != (short *)0x0) {
      if (*psVar2 == sVar1) {
        puVar4 = (undefined4 *)malloc(0x14);
        if (puVar4 != (undefined4 *)0x0) {
          uVar5 = zcl_convert_attr_list_to_array(param_2);
          uStack_38 = CONCAT22(extraout_a0,0xf);
          if (param_3 == 1) {
            puVar6 = &zb_zcl_binary_input_init_server;
          }
          else if (param_3 == 2) {
            puVar6 = &zb_zcl_binary_input_init_client;
          }
          else {
            puVar6 = (undefined *)0x0;
          }
          _uStack_30 = CONCAT13((char)puVar6,(uint3)(byte)param_3);
          uStack_2c = (undefined2)((uint)puVar6 >> 8);
          *puVar4 = uStack_38;
          puVar4[1] = uVar5;
          puVar4[2] = _uStack_30;
          *(undefined2 *)(puVar4 + 3) = uStack_2c;
          *(undefined1 *)((int)puVar4 + 0xe) = 0;
          puVar4[4] = *(undefined4 *)(psVar2 + 8);
          *(undefined4 **)(param_1 + 0x10) = puVar4;
          zb_cluster_node_free(psVar2);
          return 0;
        }
        uVar5 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC21,uVar5,"ESP_ZIGBEE_CLUSTER",
                      "esp_zb_cluster_list_update_binary_input_cluster",0xa65,sVar1);
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
      esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC22,uVar5,"ESP_ZIGBEE_CLUSTER",
                    "esp_zb_cluster_list_update_binary_input_cluster",0xa7f,sVar1);
    }
  }
  else {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_L0,uVar5,"ESP_ZIGBEE_CLUSTER",
                  "esp_zb_cluster_list_update_binary_input_cluster",0xa5f);
  }
  return iVar3;
}

