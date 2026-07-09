/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_identify.o -> touchlink_send_identify_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_send_identify_req(undefined2 param_1,undefined1 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  pcStack_18 = (code *)0x0;
  uStack_14 = 0;
  if (param_2 == (undefined1 *)0x0) {
    uVar2 = 2;
  }
  else {
    iVar1 = touchlink_transaction_id(0);
    if (iVar1 == 0) {
      uVar2 = 3;
    }
    else {
      uStack_20 = touchlink_transaction_id(0);
      uStack_1c = CONCAT22(uStack_1c._2_2_,param_1);
      pcStack_18 = touchlink_identify_req_confirm;
      uStack_2c = CONCAT31(uStack_2c._1_3_,3);
      uStack_28 = *(undefined4 *)(param_2 + 2);
      uStack_2c = CONCAT13(param_2[1],CONCAT12(*param_2,(undefined2)uStack_2c));
      uStack_24 = CONCAT22(uStack_24._2_2_,*(undefined2 *)(param_2 + 6));
      uStack_14 = param_3;
      uVar2 = zcl_touchlink_identify_req(&uStack_2c);
    }
  }
  return uVar2;
}

