/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_api.o -> ezb_af_create_gateway_endpoint
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * ezb_af_create_gateway_endpoint(undefined1 *param_1)

{
  undefined1 *puVar1;
  
  puVar1 = param_1;
  if ((param_1 != (undefined1 *)0x0) &&
     (puVar1 = (undefined1 *)af_create_endpoint_desc(), puVar1 != (undefined1 *)0x0)) {
    af_endpoint_set_gateway();
    ezb_zcl_alarms_cluster_client_init(*param_1);
    ezb_zcl_identify_cluster_client_init(*param_1);
    ezb_zcl_groups_cluster_client_init(*param_1);
    ezb_zcl_scenes_cluster_client_init(*param_1);
    ezb_zcl_door_lock_cluster_client_init(*param_1);
    ezb_zcl_temperature_measurement_cluster_client_init(*param_1);
    ezb_zcl_ias_ace_cluster_client_init(*param_1);
    ezb_zcl_ias_zone_cluster_client_init(*param_1);
    ezb_zcl_thermostat_cluster_client_init(*param_1);
  }
  return puVar1;
}

