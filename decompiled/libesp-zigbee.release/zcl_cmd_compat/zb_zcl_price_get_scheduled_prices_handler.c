/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_price_get_scheduled_prices_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_price_get_scheduled_prices_handler(undefined2 *param_1,code *param_2)

{
  void *__src;
  uint uVar1;
  undefined2 uStack_74;
  undefined2 uStack_72;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  int iStack_68;
  undefined1 auStack_64 [10];
  undefined2 uStack_5a;
  undefined1 auStack_58 [12];
  undefined1 auStack_4c [64];
  
  uStack_72 = param_1[1];
  uStack_70 = *(undefined4 *)(param_1 + 6);
  uStack_74 = *param_1;
  iStack_68 = 0;
  uStack_6c = (uint)*(byte *)(param_1 + 8);
  if (param_2 != (code *)0x0) {
    (*param_2)(0x4c,&uStack_74,param_2);
  }
  if (uStack_6c._1_1_ == '\0') {
    *(undefined1 *)(param_1 + 10) = 0x8b;
  }
  else {
    *(undefined1 *)(param_1 + 10) = 0;
    memset(auStack_58,0,0x48);
    __src = *(void **)(param_1 + 4);
    memcpy(auStack_64,__src,10);
    uStack_5a = *(undefined2 *)((int)__src + 0x14);
    for (uVar1 = 0; (uVar1 & 0xffff) < (uStack_6c >> 8 & 0xff); uVar1 = uVar1 + 1) {
      memcpy(auStack_4c,(void *)(iStack_68 + uVar1 * 0x3b),0x3b);
      ezb_zcl_price_publish_price_cmd_req(auStack_64);
    }
  }
  return;
}

