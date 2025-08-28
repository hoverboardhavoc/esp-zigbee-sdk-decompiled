/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_alarms.o -> zb_zcl_alarms_req_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_zcl_alarms_req_resp_handler(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = zb_buf_get_tail_func(0x1b);
  if (param_1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_ALARMS",&_LC5,uVar3,"ESP_ZIGBEE_ZCL_ALARMS",
                  "zb_zcl_alarms_req_resp_handler",0x19b);
    iVar2 = 0;
  }
  else if (iVar1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = esp_zb_has_core_action_handler();
    if (iVar2 != 0) {
      if ((*(char *)(iVar1 + 0x14) == '\0') &&
         (iVar2 = esp_zb_zcl_get_cluster(*(undefined1 *)(iVar1 + 0xc),9,1), iVar2 != 0)) {
        if (*(char *)(iVar1 + 0x13) == '\x02') {
          iVar2 = zcl_alarms_get_alarm_handler(param_1);
        }
        else if (*(char *)(iVar1 + 0x13) == '\x03') {
          iVar2 = zcl_alarms_reset_alarm_log_handler(param_1);
        }
        else {
          iVar2 = 0;
        }
      }
      else if (*(char *)(iVar1 + 0x14) == '\x01') {
        iVar2 = esp_zb_zcl_get_cluster(*(undefined1 *)(iVar1 + 0xc),9,2);
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else if (*(char *)(iVar1 + 0x13) == '\x01') {
          iVar2 = zcl_alarms_get_alarm_resp_handler(param_1);
        }
        else {
          iVar2 = 0;
        }
      }
      else {
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}

