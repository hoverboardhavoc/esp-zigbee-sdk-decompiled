/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_ep_list_add_gateway_ep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_ep_list_add_gateway_ep
               (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    param_2 = esp_zb_zcl_cluster_list_create();
    uVar2 = basic_cluster_create(0);
    cluster_list_add_basic_cluster(param_2,uVar2,1);
    uVar2 = identify_cluster_create(0);
    cluster_list_add_identify_cluster(param_2,uVar2,1);
    if (param_2 == 0) {
      puVar1 = (undefined1 *)0x0;
      goto _L0;
    }
  }
  puVar1 = (undefined1 *)(param_2 + -4);
_L0:
  puVar1[1] = puVar1[1] | 1;
  ezb_zcl_alarms_cluster_client_init(*puVar1);
  ezb_zcl_identify_cluster_client_init(*puVar1);
  ezb_zcl_groups_cluster_client_init(*puVar1);
  ezb_zcl_scenes_cluster_client_init(*puVar1);
  ezb_zcl_door_lock_cluster_client_init(*puVar1);
  ezb_zcl_temperature_measurement_cluster_client_init(*puVar1);
  ezb_zcl_ias_ace_cluster_client_init(*puVar1);
  ezb_zcl_ias_zone_cluster_client_init(*puVar1);
  ezb_zcl_thermostat_cluster_client_init(*puVar1);
  zb_zcl_custom_cluster_init(*puVar1);
  esp_zb_ep_list_add_ep(param_1,param_2,param_3,param_4);
  return;
}

