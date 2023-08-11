/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_level_control_set_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_level_control_set_value_handler(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  uStack_24 = 0;
  uStack_20 = CONCAT31(uStack_20._1_3_,*(undefined1 *)(iVar1 + 4));
  uStack_20 = CONCAT22(8,(undefined2)uStack_20);
  uStack_1c = 0x200000;
  uStack_18 = CONCAT13((char)(iVar1 + 0xc),0x10000);
  uStack_14._0_3_ = (undefined3)((uint)(iVar1 + 0xc) >> 8);
  if (zcl_level_control_set_value_cb == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    local_50 = 0;
    uStack_4c = uStack_20;
    uStack_48 = 0x200000;
    uStack_44 = uStack_18;
    uStack_40 = uStack_14;
    (*zcl_level_control_set_value_cb)(&local_50);
    uVar2 = error_to_zb_ret();
  }
  return uVar2;
}

