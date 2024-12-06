/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_cli_process_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zcl_commissioning_cli_process_response(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  byte *pbVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uStack_1c;
  ushort uStack_18;
  undefined2 uStack_16;
  uint uStack_14;
  
  uStack_1c = 0;
  uStack_14 = 0;
  _uStack_18 = CONCAT22(*(undefined2 *)(param_2 + 0x18),(ushort)*(byte *)(param_2 + 0x17));
  pbVar2 = (byte *)zb_buf_begin_func();
  uStack_14 = (uint)*pbVar2;
  uVar3 = esp_zb_core_action_handler_schedule(0x1c,&uStack_1c);
  uVar4 = zb_buf_get_tail_func(param_1,0x1b);
  uVar1 = esp_err_to_zcl_status(uVar3);
  zb_zcl_send_default_handler(param_1,uVar4,uVar1);
  return 1;
}

