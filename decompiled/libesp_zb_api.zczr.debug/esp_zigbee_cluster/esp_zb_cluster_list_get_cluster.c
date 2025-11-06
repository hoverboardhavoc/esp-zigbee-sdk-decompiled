/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_cluster.o -> esp_zb_cluster_list_get_cluster
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
    esp_log(1,0x10000,"E (%lu) %s: %s(%d): Invalid cluster list\n",uVar2,0x10000,
            "esp_zb_cluster_list_get_cluster",0xb2e);
    uVar2 = 0;
  }
  else {
    puVar1 = *(ushort **)(param_1 + 0x10);
    while ((puVar1 != (ushort *)0x0 && ((*puVar1 != param_2 || ((byte)puVar1[4] != param_3))))) {
      puVar1 = *(ushort **)(puVar1 + 8);
    }
    if (puVar1 == (ushort *)0x0) {
      uVar2 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: The requested cluster ID (0x%4hx) is not found\n",uVar2,0x10000
              ,param_2);
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(puVar1 + 2);
    }
  }
  return uVar2;
}

