/*
 * Last changed at upstream commit 9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * https://github.com/espressif/esp-zigbee-sdk/commit/9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * Upstream date: 2023-11-10 18:10:39 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.3(ba5a889a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_thermostat_value_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_thermostat_value_cb_handler(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20;
  undefined1 uStack_1c;
  undefined2 uStack_1a;
  undefined1 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  local_20 = 0;
  uStack_1c = *(undefined1 *)(iVar1 + 4);
  uStack_1a = 0x201;
  uStack_18 = *(undefined1 *)(iVar1 + 0xc);
  uStack_16 = *(undefined2 *)(iVar1 + 0xe);
  uStack_14 = *(undefined2 *)(iVar1 + 0x10);
  if (zb_core_action_cb == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    (*zb_core_action_cb)(7,&local_20);
    uVar2 = esp_err_to_zb_ret();
  }
  return uVar2;
}

