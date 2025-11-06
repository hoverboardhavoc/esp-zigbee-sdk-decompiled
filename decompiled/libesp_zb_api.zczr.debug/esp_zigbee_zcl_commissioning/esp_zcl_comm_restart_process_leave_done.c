/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_comm_restart_process_leave_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zcl_comm_restart_process_leave_done(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zb_buf_get_tail_func(2);
  if (*(char *)(iVar1 + 1) == '\0') {
    uVar2 = esp_log_timestamp();
    esp_log(3,"ESP_ZIGBEE_ZCL_COMMISSIONING","I (%lu) %s: Successfully leave network\n",uVar2,
            "ESP_ZIGBEE_ZCL_COMMISSIONING");
    esp_zcl_comm_restart_process_install(param_1,esp_zcl_commissioning_restart_process_rejoin);
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_COMMISSIONING","E (%lu) %s: Failed to leave network: ret = %d\n",uVar2
            ,"ESP_ZIGBEE_ZCL_COMMISSIONING",*(undefined1 *)(iVar1 + 1));
    zb_buf_free_func(param_1);
  }
  return;
}

