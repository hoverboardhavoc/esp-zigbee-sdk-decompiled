/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_process_restart_device_continue
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
    zb_schedule_alarm(esp_zcl_comm_restart_process_start,param_1,DAT_00010e00 * 1000,
                      (int)((ulonglong)DAT_00010e00 * 1000 >> 0x20) + DAT_00010e04 * 1000);
    DAT_00010e00 = 0;
    DAT_00010e04 = 0;
    return;
  }
  uVar2 = esp_log_timestamp();
  esp_log(1,"ESP_ZIGBEE_ZCL_COMMISSIONING",
          "E (%lu) %s: Fail to send response, abort the restart process\n",uVar2,
          "ESP_ZIGBEE_ZCL_COMMISSIONING");
  zb_buf_free_func(param_1);
  return;
}

