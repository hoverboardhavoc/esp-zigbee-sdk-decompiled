/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_ias_zone_enroll_response_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_ias_zone_enroll_response_handler(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  uStack_14 = *(undefined2 *)(iVar1 + 0xc);
  uStack_20 = 0;
  uStack_1c = CONCAT31(uStack_1c._1_3_,*(undefined1 *)(iVar1 + 4));
  uStack_1c = CONCAT22(0x500,(undefined2)uStack_1c);
  uStack_18 = CONCAT22(uStack_18._2_2_,uStack_14);
  if (zcl_ias_zone_enroll_resp_cb == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    local_30 = 0;
    uStack_2c = uStack_1c;
    uStack_28 = uStack_18;
    (*zcl_ias_zone_enroll_resp_cb)(&local_30);
    uVar2 = error_to_zb_ret();
  }
  return uVar2;
}

