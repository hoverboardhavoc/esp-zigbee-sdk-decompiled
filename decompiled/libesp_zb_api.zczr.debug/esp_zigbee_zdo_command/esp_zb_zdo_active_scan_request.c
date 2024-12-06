/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> esp_zb_zdo_active_scan_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_active_scan_request(undefined4 param_1,undefined1 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_API_ZDO",&_LC16,uVar3,"ESP_ZIGBEE_API_ZDO",
                  "esp_zb_zdo_active_scan_request",0x105);
  }
  else {
    puVar2 = (undefined4 *)zb_buf_get_tail_func(0xc);
    puVar2[2] = active_scan_complete_cb;
    *puVar2 = param_1;
    *(undefined1 *)(puVar2 + 1) = param_2;
    zdo_active_scan_user_cb = param_3;
    zb_schedule_app_alarm(&zb_zdo_active_scan_request,iVar1,0,0);
  }
  return;
}

