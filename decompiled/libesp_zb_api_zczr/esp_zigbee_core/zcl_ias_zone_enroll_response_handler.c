/*
 * Last changed at upstream commit 9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * https://github.com/espressif/esp-zigbee-sdk/commit/9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * Upstream date: 2023-11-10 18:10:39 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.3(ba5a889a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_ias_zone_enroll_response_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_ias_zone_enroll_response_handler(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined1 uStack_1c;
  undefined2 uStack_1a;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined2 uStack_14;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  uVar1 = *(undefined2 *)(iVar2 + 0xc);
  local_20 = 0;
  uStack_1c = *(undefined1 *)(iVar2 + 4);
  uStack_1a = 0x500;
  uStack_14._0_1_ = (undefined1)uVar1;
  uStack_18 = (undefined1)uStack_14;
  uStack_14._1_1_ = (undefined1)((ushort)uVar1 >> 8);
  uStack_17 = uStack_14._1_1_;
  if (zb_core_action_cb == (code *)0x0) {
    uVar3 = 0;
  }
  else {
    uStack_14 = uVar1;
    (*zb_core_action_cb)(3,&local_20);
    uVar3 = esp_err_to_zb_ret();
  }
  return uVar3;
}

