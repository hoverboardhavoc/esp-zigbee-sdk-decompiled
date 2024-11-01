/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_cluster_list_get_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_list_get_cluster(int param_1,uint param_2,uint param_3)

{
  ushort *puVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_L0,uVar2,0x10000,"esp_zb_cluster_list_get_cluster",0x98d);
    uVar2 = 0;
  }
  else {
    puVar1 = *(ushort **)(param_1 + 0x10);
    while ((puVar1 != (ushort *)0x0 && ((*puVar1 != param_2 || ((byte)puVar1[4] != param_3))))) {
      puVar1 = *(ushort **)(puVar1 + 8);
    }
    if (puVar1 == (ushort *)0x0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC17,uVar2,0x10000,param_2);
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(puVar1 + 2);
    }
  }
  return uVar2;
}

