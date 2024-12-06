/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
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

