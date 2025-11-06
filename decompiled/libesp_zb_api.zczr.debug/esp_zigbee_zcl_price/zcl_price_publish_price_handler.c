/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_price.o -> zcl_price_publish_price_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_price_publish_price_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  void *__src;
  undefined1 auStack_54 [4];
  undefined1 uStack_50;
  undefined2 uStack_4e;
  undefined1 auStack_4c [60];
  
  iVar1 = zb_buf_get_tail_func(0x38);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  __src = *(void **)(iVar2 + 0x10);
  memset(auStack_54,0,0x44);
  uStack_50 = *(undefined1 *)(iVar1 + 4);
  uStack_4e = 0x700;
  memcpy(auStack_4c,__src,0x3b);
  esp_zb_core_action_handler_schedule(0x17,auStack_54);
  esp_err_to_zb_ret();
  return;
}

