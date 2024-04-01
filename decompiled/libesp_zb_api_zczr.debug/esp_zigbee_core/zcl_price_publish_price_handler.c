/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> zcl_price_publish_price_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_price_publish_price_handler(undefined4 param_1)

{
  void *__src;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
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
    uVar3 = 0;
  }
  else {
    (*zb_core_action_cb)(0x17,auStack_54);
    uVar3 = esp_err_to_zb_ret();
  }
  return uVar3;
}

