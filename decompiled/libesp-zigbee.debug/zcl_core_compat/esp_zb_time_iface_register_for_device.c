/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_core_compat.o -> esp_zb_time_iface_register_for_device
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_time_iface_register_for_device(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  while (iVar1 = ezb_af_device_desc_get_next_endpoint_desc(param_1,iVar1), iVar1 != 0) {
    iVar2 = ezb_af_endpoint_get_cluster_desc(iVar1,10,1);
    if (iVar2 != 0) {
      ezb_af_ep_desc_get_ep_id(iVar1);
      ezb_zcl_time_server_interface_register(time_cluster_get_utc_time,time_cluster_set_utc_time);
    }
  }
  return;
}

