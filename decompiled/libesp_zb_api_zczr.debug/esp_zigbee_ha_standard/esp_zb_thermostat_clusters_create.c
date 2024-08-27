/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_ha_standard.o -> esp_zb_thermostat_clusters_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_thermostat_clusters_create(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_1 == 0) {
    iVar1 = 0;
    iVar4 = 0;
  }
  else {
    iVar4 = param_1 + 2;
    iVar1 = param_1 + 4;
  }
  uVar2 = esp_zb_zcl_cluster_list_create();
  uVar3 = esp_zb_basic_cluster_create(param_1);
  esp_zb_cluster_list_add_basic_cluster(uVar2,uVar3,1);
  uVar3 = esp_zb_identify_cluster_create(iVar4);
  esp_zb_cluster_list_add_identify_cluster(uVar2,uVar3,1);
  uVar3 = esp_zb_zcl_attr_list_create(3);
  esp_zb_cluster_list_add_identify_cluster(uVar2,uVar3,2);
  uVar3 = esp_zb_thermostat_cluster_create(iVar1);
  esp_zb_cluster_list_add_thermostat_cluster(uVar2,uVar3,1);
  return uVar2;
}

