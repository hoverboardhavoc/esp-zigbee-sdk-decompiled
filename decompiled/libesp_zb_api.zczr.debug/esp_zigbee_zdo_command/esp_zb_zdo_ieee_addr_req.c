/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> esp_zb_zdo_ieee_addr_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_ieee_addr_req(undefined2 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  
  iVar1 = zb_buf_get_out_func();
  if (param_1 == (undefined2 *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_API_ZDO",&_LC23,uVar3,"ESP_ZIGBEE_API_ZDO",
                  "esp_zb_zdo_ieee_addr_req",500);
  }
  else if (iVar1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_API_ZDO",&_LC24,uVar3,"ESP_ZIGBEE_API_ZDO",
                  "esp_zb_zdo_ieee_addr_req",0x1f5);
  }
  else {
    puVar2 = (undefined2 *)zb_buf_get_tail_func(6);
    *puVar2 = *param_1;
    puVar2[1] = param_1[1];
    *(undefined1 *)(puVar2 + 2) = *(undefined1 *)(param_1 + 2);
    *(undefined1 *)((int)puVar2 + 5) = *(undefined1 *)((int)param_1 + 5);
    uVar3 = zb_zdo_ieee_addr_req(iVar1,device_ieee_addr_req_cb);
    zb_schedule_app_alarm(ieee_addr_req_timeout,uVar3,5000000,0);
    esp_zb_zdo_callback_register(uVar3,1,param_2,param_3);
  }
  return;
}

