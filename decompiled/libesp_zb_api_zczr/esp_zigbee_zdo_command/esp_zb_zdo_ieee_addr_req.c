/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_ieee_addr_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_ieee_addr_req(undefined2 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  
  uVar1 = zb_buf_get_out_func();
  puVar2 = (undefined2 *)zb_buf_get_tail_func(6);
  *puVar2 = *param_1;
  puVar2[1] = param_1[1];
  *(undefined1 *)(puVar2 + 2) = *(undefined1 *)(param_1 + 2);
  *(undefined1 *)((int)puVar2 + 5) = *(undefined1 *)((int)param_1 + 5);
  uVar1 = zb_zdo_ieee_addr_req(uVar1,device_ieee_addr_req_cb);
  zb_schedule_app_alarm(ieee_addr_req_timeout,uVar1,0x14a,0);
  esp_zb_zdo_callback_register(uVar1,1,param_2,param_3);
  return;
}

