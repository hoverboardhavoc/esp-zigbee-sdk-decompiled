/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_core.o -> zb_zcl_basic_message_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_basic_message_create(undefined4 *param_1)

{
  undefined1 uVar1;
  void *__src;
  undefined4 uVar2;
  
  __src = (void *)zb_buf_get_tail_func(0x1b);
  if (__src == (void *)0x0) {
    *param_1 = 1;
    uVar2 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined1 *)((int)__src + 0xd);
    *param_1 = 0;
    *(undefined1 *)(param_1 + 1) = uVar1;
    *(undefined2 *)((int)param_1 + 6) = *(undefined2 *)((int)__src + 0x19);
    *(undefined1 *)(param_1 + 2) = *(undefined1 *)((int)__src + 0x15);
    *(undefined1 *)((int)param_1 + 9) = *(undefined1 *)((int)__src + 0xe);
    memcpy((void *)((int)param_1 + 10),__src,9);
    uVar2 = 0;
    *(undefined2 *)(param_1 + 5) = *(undefined2 *)((int)__src + 9);
    *(undefined1 *)((int)param_1 + 0x16) = *(undefined1 *)((int)__src + 0xb);
    *(undefined1 *)((int)param_1 + 0x17) = *(undefined1 *)((int)__src + 0xc);
    *(undefined2 *)(param_1 + 6) = *(undefined2 *)((int)__src + 0xf);
    *(undefined2 *)((int)param_1 + 0x1a) = *(undefined2 *)((int)__src + 0x11);
    *(undefined1 *)((int)param_1 + 0x1d) = *(undefined1 *)((int)__src + 0x14);
    *(undefined1 *)((int)param_1 + 0x1e) = *(undefined1 *)((int)__src + 0x16);
    *(undefined1 *)(param_1 + 7) = *(undefined1 *)((int)__src + 0x13);
  }
  return uVar2;
}

