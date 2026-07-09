/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_factory_new.o -> touchlink_send_factory_new_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_send_factory_new_req(void *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [10];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  memset(auStack_28,0,0x18);
  uVar1 = 2;
  if (param_1 != (void *)0x0) {
    piVar2 = (int *)touchlink_transaction_get(2);
    uVar1 = 3;
    if (*piVar2 != 0) {
      uStack_1c = touchlink_transaction_id(0);
      uStack_18 = 0x10000;
      auStack_28[0] = 3;
      uStack_14 = param_2;
      memcpy(auStack_26,param_1,8);
      uVar1 = zcl_touchlink_reset_to_factory_new_req(auStack_28);
    }
  }
  return uVar1;
}

