/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_get_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_list_get_cluster(int param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  ushort *puVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  puVar2 = *(ushort **)(param_1 + 0x10);
  while( true ) {
    if (puVar2 == (ushort *)0x0) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC19,uVar1,"ESP_ZIGBEE_CLUSTER",param_2);
      return 0;
    }
    if ((*puVar2 == param_2) && ((byte)puVar2[4] == param_3)) break;
    puVar2 = *(ushort **)(puVar2 + 8);
  }
  return *(undefined4 *)(puVar2 + 2);
}

