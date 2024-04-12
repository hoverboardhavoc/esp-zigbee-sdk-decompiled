/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_cluster_list_update_basic_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_update_basic_cluster(int param_1,int param_2,int param_3)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int extraout_a1;
  undefined *puVar6;
  int iStack_38;
  uint3 uStack_30;
  undefined1 uStack_2d;
  undefined2 uStack_2c;
  
  sVar1 = *(short *)(*(int *)(param_2 + 0xc) + 10);
  iVar3 = esp_zb_cluster_list_check(0);
  if (iVar3 == 0) {
    psVar2 = *(short **)(param_1 + 0x10);
    while (psVar2 != (short *)0x0) {
      if (*psVar2 == sVar1) {
        piVar4 = (int *)malloc(0x14);
        if (piVar4 != (int *)0x0) {
          iStack_38 = zcl_convert_attr_list_to_array(param_2);
          iStack_38 = iStack_38 << 0x10;
          if (param_3 == 1) {
            puVar6 = &esp_zb_zcl_basic_init_server;
          }
          else if (param_3 == 2) {
            puVar6 = &zb_zcl_basic_init_client;
          }
          else {
            puVar6 = (undefined *)0x0;
          }
          _uStack_30 = CONCAT13((char)puVar6,(uint3)(byte)param_3);
          uStack_2c = (undefined2)((uint)puVar6 >> 8);
          *piVar4 = iStack_38;
          piVar4[1] = extraout_a1;
          piVar4[2] = _uStack_30;
          *(undefined2 *)(piVar4 + 3) = uStack_2c;
          *(undefined1 *)((int)piVar4 + 0xe) = 0;
          piVar4[4] = *(int *)(psVar2 + 8);
          *(int **)(param_1 + 0x10) = piVar4;
          zb_cluster_node_free(psVar2);
          return 0;
        }
        uVar5 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC21,uVar5,"ESP_ZIGBEE_CLUSTER",
                      "esp_zb_cluster_list_update_basic_cluster",0x86b,sVar1);
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
                    "esp_zb_cluster_list_update_basic_cluster",0x885,sVar1);
    }
  }
  else {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_L0,uVar5,"ESP_ZIGBEE_CLUSTER",
                  "esp_zb_cluster_list_update_basic_cluster",0x865);
  }
  return iVar3;
}

