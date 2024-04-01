/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_price_publish_price_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_price_publish_price_handler(undefined4 param_1)

{
  void *__src;
  int iVar1;
  int iVar2;
  undefined1 auStack_54 [4];
  undefined1 uStack_50;
  undefined2 uStack_4e;
  undefined1 auStack_4c [64];
  
  iVar1 = zb_buf_get_tail_func(0x38);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  __src = *(void **)(iVar2 + 0x10);
  memset(auStack_54,0,0x44);
  uStack_50 = *(undefined1 *)(iVar1 + 4);
  uStack_4e = 0x700;
  memcpy(auStack_4c,__src,0x3b);
  if (zb_core_action_cb == (code *)0x0) {
    return 0;
  }
  iVar1 = (*zb_core_action_cb)(0x17,auStack_54);
  if (iVar1 == 0x105) {
    iVar2 = -0x1c;
  }
  else if (iVar1 < 0x106) {
    iVar2 = -0x16;
    if ((iVar1 != 0x101) && (iVar2 = -6, iVar1 != 0x104)) {
      return -(uint)(iVar1 != 0);
    }
  }
  else {
    iVar2 = -0x1e;
    if ((iVar1 != 0x107) && (iVar2 = -2, iVar1 != 0x10c)) {
      return -1;
    }
  }
  return iVar2;
}

