/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_simple_desc_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_simple_desc_req(undefined2 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = zb_buf_get_out_func();
  puVar2 = (undefined1 *)zb_buf_initial_alloc_func(3);
  puVar2[2] = *(undefined1 *)(param_1 + 1);
  *puVar2 = *(undefined1 *)param_1;
  puVar2[1] = (char)((ushort)*param_1 >> 8);
  uVar1 = zb_zdo_simple_desc_req(uVar1,simple_desc_cb);
  zb_schedule_app_alarm(simple_desc_req_timeout,uVar1,5000000,0);
  esp_zb_zdo_callback_register(uVar1,4,param_2,param_3);
  return;
}

