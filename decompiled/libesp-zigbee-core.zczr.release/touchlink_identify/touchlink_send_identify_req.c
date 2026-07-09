/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_identify.o -> touchlink_send_identify_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_send_identify_req(undefined2 param_1,void *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_2c [2];
  undefined1 auStack_2a [10];
  undefined4 uStack_20;
  undefined2 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  memset(auStack_2c,0,0x1c);
  uVar1 = 2;
  if (param_2 != (void *)0x0) {
    iVar2 = touchlink_transaction_id(0);
    uVar1 = 3;
    if (iVar2 != 0) {
      uStack_20 = touchlink_transaction_id(0);
      uStack_18 = 0x10000;
      auStack_2c[0] = 3;
      uStack_1c = param_1;
      uStack_14 = param_3;
      memcpy(auStack_2a,param_2,8);
      uVar1 = zcl_touchlink_identify_req(auStack_2c);
    }
  }
  return uVar1;
}

