/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_process_restart_device_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zcl_commissioning_process_restart_device_continue(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)zb_buf_get_tail_func(0x10);
  if (*piVar1 == 0) {
    uVar2 = esp_log_timestamp();
    uVar3 = __udivdi3(DAT_000117f8,DAT_000117fc,1000,0);
    esp_log_write(3,"ESP_ZIGBEE_ZCL_COMMISSIONING",&_L0,uVar2,"ESP_ZIGBEE_ZCL_COMMISSIONING",uVar3);
    zb_schedule_alarm(esp_zcl_comm_restart_process_start,param_1,DAT_000117f8 * 1000,
                      (int)((ulonglong)DAT_000117f8 * 1000 >> 0x20) + DAT_000117fc * 1000);
    DAT_000117f8 = 0;
    DAT_000117fc = 0;
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_COMMISSIONING",&_LC4,uVar2,"ESP_ZIGBEE_ZCL_COMMISSIONING");
    zb_buf_free_func(param_1);
  }
  return;
}

