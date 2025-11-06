/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
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
    esp_log(1,"ESP_ZIGBEE_API_ZDO","E (%lu) %s: %s(%d): Invalid parameter\n",uVar3,
            "ESP_ZIGBEE_API_ZDO","esp_zb_zdo_mgmt_lqi_req",0x498);
  }
  else {
    iVar1 = zb_buf_get_out_func();
    if (iVar1 == 0) {
      uVar3 = esp_log_timestamp();
      esp_log(1,"ESP_ZIGBEE_API_ZDO","E (%lu) %s: %s(%d): No I/O buffer to LQI request\n",uVar3,
              "ESP_ZIGBEE_API_ZDO","esp_zb_zdo_mgmt_lqi_req",0x499);
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

