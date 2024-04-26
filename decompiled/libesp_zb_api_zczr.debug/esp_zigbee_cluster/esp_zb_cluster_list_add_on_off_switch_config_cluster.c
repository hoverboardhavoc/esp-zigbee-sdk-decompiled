/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_on_off_switch_config_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
esp_zb_cluster_list_add_on_off_switch_config_cluster(int param_1,int param_2,uint param_3)

{
  short *psVar1;
  short *psVar2;
  undefined2 extraout_a0;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined4 uStack_38;
  uint3 uStack_30;
  undefined1 uStack_2d;
  undefined2 uStack_2c;
  
  puVar3 = (undefined4 *)malloc(0x14);
  if (param_1 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC3,uVar4,"ESP_ZIGBEE_CLUSTER");
    uVar4 = 0x102;
  }
  else if (*(short *)(*(int *)(param_2 + 0xc) + 10) == 7) {
    psVar1 = *(short **)(param_1 + 0x10);
    do {
      psVar2 = psVar1;
      if (psVar2 == (short *)0x0) break;
      if (*psVar2 == 7 && *(byte *)(psVar2 + 4) == param_3) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_L0,uVar4,"ESP_ZIGBEE_CLUSTER",7);
        return 0x102;
      }
      psVar1 = *(short **)(psVar2 + 8);
    } while (*(short **)(psVar2 + 8) != (short *)0x0);
    uVar4 = zcl_convert_attr_list_to_array(param_2);
    uStack_38 = CONCAT22(extraout_a0,7);
    if (param_3 == 1) {
      puVar5 = &zb_zcl_on_off_switch_config_init_server;
    }
    else if (param_3 == 2) {
      puVar5 = &zb_zcl_on_off_switch_config_init_client;
    }
    else {
      puVar5 = (undefined *)0x0;
    }
    _uStack_30 = CONCAT13((char)puVar5,(uint3)(byte)param_3);
    uStack_2c = (undefined2)((uint)puVar5 >> 8);
    *puVar3 = uStack_38;
    puVar3[1] = uVar4;
    puVar3[2] = _uStack_30;
    *(undefined2 *)(puVar3 + 3) = uStack_2c;
    *(undefined1 *)((int)puVar3 + 0xe) = 0;
    puVar3[4] = 0;
    if (psVar2 == (short *)0x0) {
      *(undefined4 **)(param_1 + 0x10) = puVar3;
      uVar4 = 0;
    }
    else {
      *(undefined4 **)(psVar2 + 8) = puVar3;
      uVar4 = 0;
    }
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC20,uVar4,"ESP_ZIGBEE_CLUSTER");
    uVar4 = 0x102;
  }
  return uVar4;
}

