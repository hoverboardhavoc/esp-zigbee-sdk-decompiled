/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_door_lock_lock_unlock_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_door_lock_lock_unlock_resp_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_20;
  ushort uStack_1c;
  undefined2 uStack_1a;
  uint uStack_18;
  uint uStack_14;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  local_20 = 0;
  _uStack_1c = CONCAT22(0x101,(ushort)*(byte *)(*(int *)(iVar2 + 0xc) + 0xc));
  uStack_18 = 0;
  uStack_14 = 0;
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  uStack_18 = (uint)*(byte *)(*(int *)(iVar2 + 0xc) + 0x13);
  zb_buf_get_tail_func(param_1,0x38);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  uStack_14 = (uint)**(byte **)(iVar2 + 0x10);
  if (zb_core_action_cb == (code *)0x0) {
    return 0;
  }
  iVar2 = (*zb_core_action_cb)(0x11,&local_20);
  if (iVar2 == 0x105) {
    iVar1 = -0x1c;
  }
  else if (iVar2 < 0x106) {
    iVar1 = -0x16;
    if ((iVar2 != 0x101) && (iVar1 = -6, iVar2 != 0x104)) {
      return -(uint)(iVar2 != 0);
    }
  }
  else {
    iVar1 = -0x1e;
    if ((iVar2 != 0x107) && (iVar1 = -2, iVar2 != 0x10c)) {
      return -1;
    }
  }
  return iVar1;
}

