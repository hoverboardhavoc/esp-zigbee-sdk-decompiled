/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_thermostat.o -> zb_zcl_thermostat_client_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_zcl_thermostat_client_resp_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = zb_buf_get_tail_func(0x1b);
  if (iVar1 == 0) {
    iVar4 = 0;
  }
  else if (*(char *)(iVar1 + 0x14) == '\x01') {
    iVar4 = esp_zb_has_core_action_handler();
    if (iVar4 != 0) {
      if (*(char *)(iVar1 + 0x13) == '\0') {
        iVar2 = zcl_thermostat_get_weekly_schedule_res(param_1);
        zb_zcl_send_default_handler(param_1,iVar1,iVar2 != 0);
      }
      else {
        uVar3 = esp_log_timestamp();
        esp_log_write(2,"ESP_ZIGBEE_ZCL_THERMOSTAT",&_L0,uVar3,"ESP_ZIGBEE_ZCL_THERMOSTAT",
                      *(undefined1 *)(iVar1 + 0x13));
        iVar4 = 0;
      }
    }
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}

