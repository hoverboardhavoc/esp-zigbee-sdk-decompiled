/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zdo_command.o -> esp_zb_zdo_binding_table_req
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
  zb_schedule_app_alarm(device_binding_table_req_timeout,uVar1,0x14a,0);
  esp_zb_zdo_callback_register(uVar1,0x33,param_2,param_3);
  return;
}

