/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zdo_command.o -> esp_zb_zdo_energy_detect_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_energy_detect_request(undefined4 param_1,undefined1 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_API_ZDO",&_LC17,uVar3,"ESP_ZIGBEE_API_ZDO",
                  "esp_zb_zdo_energy_detect_request",0x133);
  }
  else {
    puVar2 = (undefined4 *)zb_buf_get_tail_func(0xc);
    *puVar2 = energy_detect_complete_cb;
    puVar2[1] = param_1;
    *(undefined1 *)(puVar2 + 2) = param_2;
    zdo_energy_detect_user_cb = param_3;
    zb_schedule_app_alarm(&zb_zdo_ed_scan_request,iVar1,0,0);
  }
  return;
}

