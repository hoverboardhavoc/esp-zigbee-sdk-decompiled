/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> esp_zb_zdo_mgmt_nwk_update_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_mgmt_nwk_update_req(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar4 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_API_ZDO","E (%lu) %s: %s(%d): Invalid parameter\n",uVar4,
            "ESP_ZIGBEE_API_ZDO","esp_zb_zdo_mgmt_nwk_update_req",0x4de);
  }
  else {
    iVar2 = zb_buf_get_out_func();
    if (iVar2 == 0) {
      uVar4 = esp_log_timestamp();
      esp_log(1,"ESP_ZIGBEE_API_ZDO","E (%lu) %s: %s(%d): No I/O buffer to NWK update request\n",
              uVar4,"ESP_ZIGBEE_API_ZDO","esp_zb_zdo_mgmt_nwk_update_req",0x4df);
    }
    else {
      puVar3 = (undefined1 *)zb_buf_get_tail_func(10);
      uVar1 = *(undefined2 *)(param_1 + 2);
      puVar3[8] = (char)uVar1;
      puVar3[9] = (char)((ushort)uVar1 >> 8);
      uVar1 = *(undefined2 *)((int)param_1 + 6);
      puVar3[6] = (char)uVar1;
      puVar3[7] = (char)((ushort)uVar1 >> 8);
      puVar3[5] = *(undefined1 *)((int)param_1 + 5);
      uVar4 = *param_1;
      *puVar3 = (char)uVar4;
      puVar3[1] = (char)((uint)uVar4 >> 8);
      puVar3[2] = (char)((uint)uVar4 >> 0x10);
      puVar3[3] = (char)((uint)uVar4 >> 0x18);
      puVar3[4] = *(undefined1 *)(param_1 + 1);
      uVar4 = zb_zdo_mgmt_nwk_update_req(iVar2,zb_zdo_nwk_update_req_cb);
      zb_schedule_app_alarm(nwk_update_req_timeout,uVar4,5000000,0);
      esp_zb_zdo_callback_register(uVar4,0x38,param_2,param_3);
    }
  }
  return;
}

