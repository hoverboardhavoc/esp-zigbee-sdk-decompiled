/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
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
    zb_schedule_alarm(esp_zcl_comm_restart_process_start,param_1,DAT_00010e10 * 1000,
                      (int)((ulonglong)DAT_00010e10 * 1000 >> 0x20) + DAT_00010e14 * 1000);
    DAT_00010e10 = 0;
    DAT_00010e14 = 0;
    return;
  }
  uVar2 = esp_log_timestamp();
  esp_log_write(1,"ESP_ZIGBEE_ZCL_COMMISSIONING",&_LC1,uVar2,"ESP_ZIGBEE_ZCL_COMMISSIONING");
  zb_buf_free_func(param_1);
  return;
}

