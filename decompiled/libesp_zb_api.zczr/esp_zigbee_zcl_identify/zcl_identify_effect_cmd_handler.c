/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_identify.o -> zcl_identify_effect_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_identify_effect_cmd_handler(void)

{
  int iVar1;
  undefined4 uStack_1c;
  ushort uStack_18;
  undefined2 uStack_16;
  uint uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  uStack_1c = 0;
  _uStack_18 = CONCAT22(3,(ushort)*(byte *)(iVar1 + 4));
  uStack_14 = (uint)*(ushort *)(iVar1 + 0xc);
  esp_zb_core_action_handler_schedule(0x12,&uStack_1c);
  esp_err_to_zb_ret();
  return;
}

