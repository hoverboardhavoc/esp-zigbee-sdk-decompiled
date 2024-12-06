/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_ias_zone.o -> zcl_ias_zone_enroll_response_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_ias_zone_enroll_response_handler(void)

{
  int iVar1;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  uStack_18 = *(undefined1 *)(iVar1 + 4);
  uStack_14 = *(undefined2 *)(iVar1 + 0xc);
  uStack_16 = 0x500;
  uStack_1c = 0;
  esp_zb_core_action_handler_schedule(3,&uStack_1c);
  esp_err_to_zb_ret();
  return;
}

