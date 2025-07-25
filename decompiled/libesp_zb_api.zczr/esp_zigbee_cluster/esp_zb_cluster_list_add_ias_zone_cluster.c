/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_ias_zone_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_list_add_ias_zone_cluster(int param_1,int param_2,uint param_3)

{
  short *psVar1;
  short *psVar2;
  short *psVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined *puVar6;
  
  puVar4 = (undefined4 *)malloc(0x14);
  if (param_1 == 0) {
    uVar5 = esp_log_timestamp();
    puVar6 = &_LC17;
  }
  else {
    if (*(short *)(*(int *)(param_2 + 0xc) + 10) == 0x500) {
      psVar3 = *(short **)(param_1 + 0x10);
      psVar2 = *(short **)(param_1 + 0x10);
      while( true ) {
        psVar1 = psVar3;
        if (psVar1 == (short *)0x0) {
          if (param_3 == 1) {
            puVar6 = &esp_zb_zcl_ias_zone_init_server;
          }
          else {
            puVar6 = (undefined *)0x0;
            if (param_3 == 2) {
              puVar6 = &esp_zb_zcl_ias_zone_init_client;
            }
          }
          *puVar4 = 0x500;
          *(char *)((int)puVar4 + 0xb) = (char)puVar6;
          *(char *)(puVar4 + 3) = (char)((uint)puVar6 >> 8);
          puVar4[1] = param_2;
          *(char *)(puVar4 + 2) = (char)param_3;
          *(undefined1 *)((int)puVar4 + 9) = 0;
          *(undefined1 *)((int)puVar4 + 10) = 0;
          *(char *)((int)puVar4 + 0xd) = (char)((uint)puVar6 >> 0x10);
          *(undefined1 *)((int)puVar4 + 0xe) = 0;
          puVar4[4] = 0;
          if (psVar2 == (short *)0x0) {
            *(undefined4 **)(param_1 + 0x10) = puVar4;
          }
          else {
            *(undefined4 **)(psVar2 + 8) = puVar4;
          }
          return 0;
        }
        if ((*psVar1 == 0x500) && (*(byte *)(psVar1 + 4) == param_3)) break;
        psVar3 = *(short **)(psVar1 + 8);
        psVar2 = psVar1;
      }
      uVar5 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC12,uVar5,"ESP_ZIGBEE_CLUSTER",0x500);
      return 0x102;
    }
    uVar5 = esp_log_timestamp();
    puVar6 = &_L0;
  }
  esp_log_write(1,"ESP_ZIGBEE_CLUSTER",puVar6,uVar5,"ESP_ZIGBEE_CLUSTER");
  return 0x102;
}

