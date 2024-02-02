/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_basic_reset_factory_reset_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_basic_reset_factory_reset_cb_handler(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_18;
  undefined1 uStack_14;
  undefined2 uStack_12;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  uStack_18 = 0;
  uStack_14 = *(undefined1 *)(iVar1 + 4);
  uStack_12 = 0;
  if (zb_core_action_cb == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    (*zb_core_action_cb)(0x13,&uStack_18);
    uVar2 = esp_err_to_zb_ret();
  }
  return uVar2;
}

