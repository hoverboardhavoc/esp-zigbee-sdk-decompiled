/*
 * Last changed at upstream commit 6663e9a47e70aeb89bdde3d1385b4fa8af6242fa
 * https://github.com/espressif/esp-zigbee-sdk/commit/6663e9a47e70aeb89bdde3d1385b4fa8af6242fa
 * Upstream date: 2023-11-21 18:28:11 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.4(be3a8a97)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_identify_effect_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_identify_effect_cmd_handler(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_1c;
  ushort uStack_18;
  undefined2 uStack_16;
  uint uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  uStack_1c = 0;
  _uStack_18 = CONCAT22(3,(ushort)*(byte *)(iVar1 + 4));
  uStack_14 = (uint)*(ushort *)(iVar1 + 0xc);
  if (zb_core_action_cb == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    (*zb_core_action_cb)(0x12,&uStack_1c);
    uVar2 = esp_err_to_zb_ret();
  }
  return uVar2;
}

