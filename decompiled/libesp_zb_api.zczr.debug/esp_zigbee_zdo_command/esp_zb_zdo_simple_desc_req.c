/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> esp_zb_zdo_simple_desc_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_simple_desc_req(undefined2 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  uVar2 = zb_buf_get_out_func();
  puVar3 = (undefined1 *)zb_buf_initial_alloc_func(3);
  puVar3[2] = *(undefined1 *)(param_1 + 1);
  uVar1 = *param_1;
  *puVar3 = (char)uVar1;
  puVar3[1] = (char)((ushort)uVar1 >> 8);
  uVar2 = zb_zdo_simple_desc_req(uVar2,simple_desc_cb);
  zb_schedule_app_alarm(simple_desc_req_timeout,uVar2,5000000,0);
  esp_zb_zdo_callback_register(uVar2,4,param_2,param_3);
  return;
}

