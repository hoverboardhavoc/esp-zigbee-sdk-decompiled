/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> zcl_basic_reset_factory_reset_cb_handler
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

