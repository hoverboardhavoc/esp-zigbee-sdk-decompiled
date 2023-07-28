/*
 * Last changed at upstream commit 992d2f5b99d09ff49d4d820bb9dc59b1d40be6d4
 * https://github.com/espressif/esp-zigbee-sdk/commit/992d2f5b99d09ff49d4d820bb9dc59b1d40be6d4
 * Upstream date: 2023-07-28 17:48:58 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.7.2(e1472baa)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_binding_table_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_binding_table_req(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = zb_buf_get_out_func();
  puVar2 = (undefined1 *)zb_buf_get_tail_func(4);
  *(undefined2 *)(puVar2 + 2) = *(undefined2 *)(param_1 + 2);
  *puVar2 = *param_1;
  uVar1 = zb_zdo_mgmt_bind_req(uVar1,zdo_binding_table_resp);
  zb_schedule_app_alarm(device_binding_table_req_timeout,uVar1,0x14a);
  esp_zb_zdo_callback_register(uVar1,0x33,param_2,param_3);
  return;
}

