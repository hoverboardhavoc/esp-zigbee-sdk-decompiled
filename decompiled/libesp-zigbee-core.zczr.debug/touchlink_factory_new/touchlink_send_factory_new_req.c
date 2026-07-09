/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_factory_new.o -> touchlink_send_factory_new_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_send_factory_new_req(undefined1 *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 == (undefined1 *)0x0) {
    uVar2 = 2;
  }
  else {
    piVar1 = (int *)touchlink_transaction_get();
    if (*piVar1 == 0) {
      uVar2 = 3;
    }
    else {
      uStack_1c = touchlink_transaction_id(0);
      uStack_18 = 0x10000;
      uStack_28 = CONCAT31(uStack_28._1_3_,3);
      uStack_24 = *(undefined4 *)(param_1 + 2);
      uStack_28 = CONCAT13(param_1[1],CONCAT12(*param_1,(undefined2)uStack_28));
      uStack_20 = CONCAT22(uStack_20._2_2_,*(undefined2 *)(param_1 + 6));
      uStack_14 = param_2;
      uVar2 = zcl_touchlink_reset_to_factory_new_req(&uStack_28);
    }
  }
  return uVar2;
}

