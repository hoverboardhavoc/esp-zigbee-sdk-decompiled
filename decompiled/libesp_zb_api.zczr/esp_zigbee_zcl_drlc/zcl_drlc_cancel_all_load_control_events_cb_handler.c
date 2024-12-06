/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_drlc.o -> zcl_drlc_cancel_all_load_control_events_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_drlc_cancel_all_load_control_events_cb_handler(undefined4 param_1)

{
  int iVar1;
  undefined4 uStack_1c;
  ushort uStack_18;
  undefined2 uStack_16;
  undefined4 uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  uStack_1c = 0;
  uStack_14 = 0;
  _uStack_18 = CONCAT22(0x701,(ushort)*(byte *)(iVar1 + 4));
  iVar1 = zb_buf_get_tail_func(param_1,0x38);
  uStack_14 = CONCAT31(uStack_14._1_3_,**(undefined1 **)(iVar1 + 0x10));
  esp_zb_core_action_handler_schedule(0x42,&uStack_1c);
  esp_err_to_zb_ret();
  return;
}

