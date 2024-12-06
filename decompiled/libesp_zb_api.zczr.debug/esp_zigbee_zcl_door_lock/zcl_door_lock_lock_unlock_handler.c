/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_door_lock.o -> zcl_door_lock_lock_unlock_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_door_lock_lock_unlock_handler(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_1c;
  ushort uStack_18;
  undefined2 uStack_16;
  uint uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  uStack_1c = 0;
  uStack_14 = 0;
  _uStack_18 = CONCAT22(0x101,(ushort)*(byte *)(*(int *)(iVar1 + 0xc) + 0xc));
  iVar1 = zb_buf_get_tail_func(param_1,0x38);
  uStack_14 = (uint)*(byte *)(*(int *)(iVar1 + 0xc) + 0x13);
  esp_zb_core_action_handler_schedule(0x10,&uStack_1c);
  uVar2 = esp_err_to_zb_ret();
  iVar1 = zb_buf_get_tail_func(param_1,0x38);
  if (*(char *)(*(int *)(iVar1 + 0xc) + 0x13) == '\0') {
    iVar1 = zb_buf_get_tail_func(param_1,0x38);
    **(undefined1 **)(iVar1 + 0x14) = (char)uVar2;
  }
  else {
    iVar1 = zb_buf_get_tail_func(param_1,0x38);
    **(undefined1 **)(iVar1 + 0x14) = (char)uVar2;
  }
  return uVar2;
}

