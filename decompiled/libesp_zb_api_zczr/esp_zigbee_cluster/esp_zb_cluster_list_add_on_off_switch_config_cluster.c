/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_on_off_switch_config_cluster
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
  short *psVar3;
  undefined2 extraout_a0;
  undefined2 *puVar4;
  undefined4 uVar5;
  undefined *puVar6;
  
  puVar4 = (undefined2 *)malloc(0x14);
  if (param_1 == 0) {
    uVar5 = esp_log_timestamp();
    puVar6 = &_LC6;
  }
  else {
    if (*(short *)(*(int *)(param_2 + 0xc) + 10) == 7) {
      psVar3 = *(short **)(param_1 + 0x10);
      psVar2 = *(short **)(param_1 + 0x10);
      while( true ) {
        psVar1 = psVar3;
        if (psVar1 == (short *)0x0) {
          uVar5 = zcl_convert_attr_list_to_array(param_2);
          if (param_3 == 1) {
            puVar6 = &zb_zcl_on_off_switch_config_init_server;
          }
          else if (param_3 == 2) {
            puVar6 = &zb_zcl_on_off_switch_config_init_client;
          }
          else {
            puVar6 = (undefined *)0x0;
          }
          *puVar4 = 7;
          *(char *)((int)puVar4 + 0xb) = (char)puVar6;
          *(char *)(puVar4 + 6) = (char)((uint)puVar6 >> 8);
          puVar4[1] = extraout_a0;
          *(undefined4 *)(puVar4 + 2) = uVar5;
          *(char *)(puVar4 + 4) = (char)param_3;
          *(undefined1 *)((int)puVar4 + 9) = 0;
          *(undefined1 *)(puVar4 + 5) = 0;
          *(char *)((int)puVar4 + 0xd) = (char)((uint)puVar6 >> 0x10);
          *(undefined1 *)(puVar4 + 7) = 0;
          *(undefined4 *)(puVar4 + 8) = 0;
          if (psVar2 == (short *)0x0) {
            *(undefined2 **)(param_1 + 0x10) = puVar4;
          }
          else {
            *(undefined2 **)(psVar2 + 8) = puVar4;
          }
          return 0;
        }
        if ((*psVar1 == 7) && (*(byte *)(psVar1 + 4) == param_3)) break;
        psVar3 = *(short **)(psVar1 + 8);
        psVar2 = psVar1;
      }
      uVar5 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_L0,uVar5,"ESP_ZIGBEE_CLUSTER",7);
      return 0x102;
    }
    uVar5 = esp_log_timestamp();
    puVar6 = &_LC13;
  }
  esp_log_write(1,"ESP_ZIGBEE_CLUSTER",puVar6,uVar5,"ESP_ZIGBEE_CLUSTER");
  return 0x102;
}

