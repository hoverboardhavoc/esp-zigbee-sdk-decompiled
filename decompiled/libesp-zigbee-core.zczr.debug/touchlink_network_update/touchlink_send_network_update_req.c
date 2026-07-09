/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_network_update.o -> touchlink_send_network_update_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_send_network_update_req(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  pcStack_18 = (code *)0x0;
  uStack_14 = 0;
  if (param_1 == 0) {
    uVar5 = 2;
  }
  else {
    iVar3 = touchlink_transaction_id(0);
    if (iVar3 == 0) {
      uVar5 = 3;
    }
    else {
      uStack_2c = touchlink_transaction_id(0);
      uVar1 = touchlink_nwk_update_id();
      uStack_20 = CONCAT31(uStack_20._1_3_,uVar1);
      uVar1 = touchlink_current_channel();
      uStack_20._0_2_ = CONCAT11(uVar1,(undefined1)uStack_20);
      uVar2 = touchlink_pan_id();
      uStack_20 = CONCAT22(uVar2,(undefined2)uStack_20);
      uStack_1c = CONCAT22(uStack_1c._2_2_,*(undefined2 *)(param_1 + 0x24));
      puVar4 = (undefined4 *)touchlink_extended_pan_id();
      uStack_28 = *puVar4;
      uStack_24 = puVar4[1];
      pcStack_18 = touchlink_network_update_req_confirm;
      uStack_38 = CONCAT31(uStack_38._1_3_,3);
      uStack_34 = *(undefined4 *)(param_1 + 0x11);
      uStack_38 = CONCAT13(*(undefined1 *)(param_1 + 0x10),
                           CONCAT12(*(undefined1 *)(param_1 + 0xf),(undefined2)uStack_38));
      uStack_30 = CONCAT22(uStack_30._2_2_,*(undefined2 *)(param_1 + 0x15));
      uStack_14 = param_2;
      uVar5 = zcl_touchlink_network_update_req(&uStack_38);
    }
  }
  return uVar5;
}

