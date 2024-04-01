/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_basic_reset_factory_reset_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_basic_reset_factory_reset_cb_handler(void)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_18;
  undefined1 uStack_14;
  undefined2 uStack_12;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  uStack_14 = *(undefined1 *)(iVar2 + 4);
  uStack_18 = 0;
  uStack_12 = 0;
  if (zb_core_action_cb == (code *)0x0) {
    return 0;
  }
  iVar2 = (*zb_core_action_cb)(0x13,&uStack_18);
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

