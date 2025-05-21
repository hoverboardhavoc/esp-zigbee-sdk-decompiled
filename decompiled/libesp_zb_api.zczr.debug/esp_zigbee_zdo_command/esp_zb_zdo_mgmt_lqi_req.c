/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> esp_zb_zdo_mgmt_lqi_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_mgmt_lqi_req(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_API_ZDO",&_LC21,uVar3,"ESP_ZIGBEE_API_ZDO","esp_zb_zdo_mgmt_lqi_req"
                  ,0x483);
  }
  else {
    iVar1 = zb_buf_get_out_func();
    if (iVar1 == 0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_API_ZDO",&_LC24,uVar3,"ESP_ZIGBEE_API_ZDO",
                    "esp_zb_zdo_mgmt_lqi_req",0x484);
    }
    else {
      puVar2 = (undefined1 *)zb_buf_get_tail_func(4);
      *puVar2 = *param_1;
      *(undefined2 *)(puVar2 + 2) = *(undefined2 *)(param_1 + 2);
      uVar3 = zb_zdo_mgmt_lqi_req(iVar1,zdo_mgmt_lqi_cb);
      zb_schedule_app_alarm(zdo_mgmt_lqi_req_timeout,uVar3,5000000,0);
      esp_zb_zdo_callback_register(uVar3,0x31,param_2,param_3);
    }
  }
  return;
}

