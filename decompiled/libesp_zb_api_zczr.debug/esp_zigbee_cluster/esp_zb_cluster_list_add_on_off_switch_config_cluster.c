/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
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
  undefined4 *puVar2;
  undefined4 uVar3;
  short *psVar4;
  undefined *puVar5;
  uint3 uStack_28;
  undefined1 uStack_25;
  undefined2 uStack_24;
  
  puVar2 = (undefined4 *)malloc(0x14);
  if (param_1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_L0,uVar3,0x10000);
    uVar3 = 0x102;
  }
  else if (*(short *)(*(int *)(param_2 + 0xc) + 10) == 7) {
    psVar1 = *(short **)(param_1 + 0x10);
    do {
      psVar4 = psVar1;
      if (psVar4 == (short *)0x0) break;
      if (*psVar4 == 7 && *(byte *)(psVar4 + 4) == param_3) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_L0,uVar3,0x10000,7);
        return 0x102;
      }
      psVar1 = *(short **)(psVar4 + 8);
    } while (*(short **)(psVar4 + 8) != (short *)0x0);
    if (param_3 == 1) {
      puVar5 = &zb_zcl_on_off_switch_config_init_server;
    }
    else if (param_3 == 2) {
      puVar5 = &zb_zcl_on_off_switch_config_init_client;
    }
    else {
      puVar5 = (undefined *)0x0;
    }
    _uStack_28 = CONCAT13((char)puVar5,(uint3)(byte)param_3);
    uStack_24 = (undefined2)((uint)puVar5 >> 8);
    *puVar2 = 7;
    puVar2[1] = param_2;
    puVar2[2] = _uStack_28;
    *(undefined2 *)(puVar2 + 3) = uStack_24;
    *(undefined1 *)((int)puVar2 + 0xe) = 0;
    puVar2[4] = 0;
    if (psVar4 == (short *)0x0) {
      *(undefined4 **)(param_1 + 0x10) = puVar2;
      uVar3 = 0;
    }
    else {
      *(undefined4 **)(psVar4 + 8) = puVar2;
      uVar3 = 0;
    }
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC13,uVar3,0x10000);
    uVar3 = 0x102;
  }
  return uVar3;
}

