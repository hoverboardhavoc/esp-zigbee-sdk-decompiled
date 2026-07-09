/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_price_get_current_price_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_price_get_current_price_handler(undefined2 *param_1,code *param_2)

{
  void *__src;
  undefined2 local_70;
  undefined2 uStack_6e;
  undefined4 uStack_6c;
  void *pvStack_68;
  undefined1 auStack_64 [10];
  undefined2 uStack_5a;
  undefined1 auStack_58 [12];
  undefined1 auStack_4c [68];
  
  uStack_6e = param_1[1];
  local_70 = *param_1;
  pvStack_68 = (void *)0x0;
  uStack_6c = (uint)*(byte *)(param_1 + 6);
  if (param_2 != (code *)0x0) {
    (*param_2)(0x4b,&local_70,param_2);
  }
  if (uStack_6c._1_1_ == '\0') {
    *(undefined1 *)(param_1 + 8) = 0x8b;
  }
  else {
    *(undefined1 *)(param_1 + 8) = 0;
    memset(auStack_58,0,0x48);
    __src = *(void **)(param_1 + 4);
    memcpy(auStack_64,__src,10);
    uStack_5a = *(undefined2 *)((int)__src + 0x14);
    memcpy(auStack_4c,pvStack_68,0x3b);
    ezb_zcl_price_publish_price_cmd_req(auStack_64);
  }
  return;
}

