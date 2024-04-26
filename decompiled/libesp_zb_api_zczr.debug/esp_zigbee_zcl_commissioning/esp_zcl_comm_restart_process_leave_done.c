/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_comm_restart_process_leave_done
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
    esp_log_write(3,"ESP_ZIGBEE_ZCL_COMMISSIONING",&_LC8,uVar2,"ESP_ZIGBEE_ZCL_COMMISSIONING");
    esp_zcl_comm_restart_process_install(param_1,esp_zcl_commissioning_restart_process_rejoin);
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_COMMISSIONING",&_L0,uVar2,"ESP_ZIGBEE_ZCL_COMMISSIONING",
                  *(undefined1 *)(iVar1 + 1));
    zb_buf_free_func(param_1);
  }
  return;
}

