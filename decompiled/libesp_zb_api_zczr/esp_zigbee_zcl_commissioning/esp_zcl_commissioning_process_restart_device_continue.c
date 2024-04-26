/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_process_restart_device_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zcl_commissioning_process_restart_device_continue(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)zb_buf_get_tail_func(0x10);
  if (*piVar1 == 0) {
    zb_schedule_alarm(esp_zcl_comm_restart_process_start,param_1,DAT_00010df0 * 1000,
                      (int)((ulonglong)DAT_00010df0 * 1000 >> 0x20) + DAT_00010df4 * 1000);
    DAT_00010df0 = 0;
    DAT_00010df4 = 0;
    return;
  }
  uVar2 = esp_log_timestamp();
  esp_log_write(1,"ESP_ZIGBEE_ZCL_COMMISSIONING",&_LC1,uVar2,"ESP_ZIGBEE_ZCL_COMMISSIONING");
  zb_buf_free_func(param_1);
  return;
}

