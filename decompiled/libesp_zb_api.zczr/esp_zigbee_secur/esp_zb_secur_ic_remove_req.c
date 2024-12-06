/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_secur.o -> esp_zb_secur_ic_remove_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_secur_ic_remove_req(void *param_1)

{
  undefined4 uVar1;
  void *__dest;
  
  uVar1 = zb_buf_get_out_func();
  __dest = (void *)zb_buf_get_tail_func(0xc);
  memcpy(__dest,param_1,8);
  *(undefined1 *)((int)__dest + 8) = 0;
  *(undefined1 *)((int)__dest + 9) = 0;
  *(undefined1 *)((int)__dest + 0xb) = 0;
  *(undefined1 *)((int)__dest + 10) = 1;
  zb_secur_ic_remove_req(uVar1);
  return ic_remove_cb_ret;
}

