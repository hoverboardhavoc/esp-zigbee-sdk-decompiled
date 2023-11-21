/*
 * Last changed at upstream commit 6663e9a47e70aeb89bdde3d1385b4fa8af6242fa
 * https://github.com/espressif/esp-zigbee-sdk/commit/6663e9a47e70aeb89bdde3d1385b4fa8af6242fa
 * Upstream date: 2023-11-21 18:28:11 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.4(be3a8a97)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_metering_request_fast_poll_mode_response_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_metering_request_fast_poll_mode_response_cb_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined1 uStack_1c;
  undefined2 uStack_1a;
  undefined1 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  local_20 = 0;
  uStack_1c = *(undefined1 *)(iVar1 + 4);
  uStack_1a = 0x702;
  uStack_18 = **(undefined1 **)(iVar2 + 0x10);
  uStack_14 = *(undefined4 *)(*(undefined1 **)(iVar2 + 0x10) + 1);
  if (zb_core_action_cb == (code *)0x0) {
    uVar3 = 0;
  }
  else {
    (*zb_core_action_cb)(0xb,&local_20);
    uVar3 = esp_err_to_zb_ret();
  }
  return uVar3;
}

