/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_core_compat.o -> esp_zb_device_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zb_device_register(esp_zb_ep_list_t *ep_list)

{
  int iVar1;
  esp_err_t eVar2;
  int iVar3;
  
  if (ep_list == (esp_zb_ep_list_t *)0x0) {
    eVar2 = 0x102;
  }
  else {
    iVar1 = ezb_af_device_desc_register();
    if (iVar1 != 0) {
      eVar2 = esp_zigbee_err_to_esp();
      return eVar2;
    }
    ezb_zcl_core_action_handler_register(zcl_core_action_handler);
    iVar1 = 0;
    while (iVar1 = ezb_af_device_desc_get_next_endpoint_desc(ep_list,iVar1), eVar2 = 0, iVar1 != 0)
    {
      iVar3 = ezb_af_endpoint_get_cluster_desc(10,1);
      if (iVar3 != 0) {
        ezb_af_ep_desc_get_ep_id(iVar1);
        ezb_zcl_time_server_interface_register(time_cluster_get_utc_time,time_cluster_set_utc_time);
      }
    }
  }
  return eVar2;
}

