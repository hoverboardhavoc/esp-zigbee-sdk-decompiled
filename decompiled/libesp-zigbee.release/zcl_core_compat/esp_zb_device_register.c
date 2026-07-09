/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_core_compat.o -> esp_zb_device_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_device_register(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    uVar2 = 0x102;
  }
  else {
    iVar1 = ezb_af_device_desc_register();
    if (iVar1 != 0) {
      uVar2 = esp_zigbee_err_to_esp();
      return uVar2;
    }
    ezb_zcl_core_action_handler_register(zcl_core_action_handler);
    iVar1 = 0;
    while (iVar1 = ezb_af_device_desc_get_next_endpoint_desc(param_1,iVar1), uVar2 = 0, iVar1 != 0)
    {
      iVar3 = ezb_af_endpoint_get_cluster_desc(10,1);
      if (iVar3 != 0) {
        ezb_af_ep_desc_get_ep_id(iVar1);
        ezb_zcl_time_server_interface_register(time_cluster_get_utc_time,time_cluster_set_utc_time);
      }
    }
  }
  return uVar2;
}

