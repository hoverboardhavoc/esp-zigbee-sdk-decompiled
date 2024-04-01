/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_door_lock_lock_unlock_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_door_lock_lock_unlock_handler(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uStack_1c;
  ushort uStack_18;
  undefined2 uStack_16;
  uint uStack_14;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  uStack_1c = 0;
  _uStack_18 = CONCAT22(0x101,(ushort)*(byte *)(*(int *)(iVar2 + 0xc) + 0xc));
  uStack_14 = 0;
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  uVar1 = 0;
  uStack_14 = (uint)*(byte *)(*(int *)(iVar2 + 0xc) + 0x13);
  if (zb_core_action_cb != (code *)0x0) {
    (*zb_core_action_cb)(0x10,&uStack_1c);
    uVar1 = esp_err_to_zb_ret();
  }
  zb_buf_get_tail_func(param_1,0x38);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  **(undefined1 **)(iVar2 + 0x14) = (char)uVar1;
  return uVar1;
}

