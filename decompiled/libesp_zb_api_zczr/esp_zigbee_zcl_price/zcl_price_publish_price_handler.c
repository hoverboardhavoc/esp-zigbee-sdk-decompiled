/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_price.o -> zcl_price_publish_price_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_price_publish_price_handler(undefined4 param_1)

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
  esp_zb_core_action_handler_schedule(0x17,auStack_54);
  esp_err_to_zb_ret();
  return;
}

