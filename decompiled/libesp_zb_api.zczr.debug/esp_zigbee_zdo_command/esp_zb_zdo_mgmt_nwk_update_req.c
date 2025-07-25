/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
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
    esp_log_write(1,"ESP_ZIGBEE_API_ZDO",&_LC23,uVar4,"ESP_ZIGBEE_API_ZDO",
                  "esp_zb_zdo_mgmt_nwk_update_req",0x4c9);
  }
  else {
    iVar2 = zb_buf_get_out_func();
    if (iVar2 == 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_API_ZDO",&_L0,uVar4,"ESP_ZIGBEE_API_ZDO",
                    "esp_zb_zdo_mgmt_nwk_update_req",0x4ca);
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

