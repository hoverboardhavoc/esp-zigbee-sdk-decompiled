/*
 * Last changed at upstream commit 9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * https://github.com/espressif/esp-zigbee-sdk/commit/9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * Upstream date: 2023-11-10 18:10:39 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.3(ba5a889a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_metering_get_profile_response_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_metering_get_profile_response_cb_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  undefined2 uStack_26;
  undefined4 uStack_24;
  uint uStack_20;
  uint uStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  puVar4 = *(undefined4 **)(iVar2 + 0x10);
  uStack_2c = 0;
  uStack_28 = *(undefined1 *)(iVar1 + 4);
  uStack_26 = 0x702;
  uStack_24 = *puVar4;
  uStack_20 = (uint)*(byte *)(puVar4 + 1);
  uStack_1c = (uint)*(byte *)((int)puVar4 + 5);
  uStack_18 = *(undefined1 *)((int)puVar4 + 6);
  uStack_14 = *(undefined4 *)((int)puVar4 + 7);
  if (zb_core_action_cb == (code *)0x0) {
    uVar3 = 0;
  }
  else {
    (*zb_core_action_cb)(9,&uStack_2c);
    uVar3 = esp_err_to_zb_ret();
  }
  return uVar3;
}

