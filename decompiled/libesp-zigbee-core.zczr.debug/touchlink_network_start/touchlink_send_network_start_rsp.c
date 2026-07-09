/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_network_start.o -> touchlink_send_network_start_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_send_network_start_rsp(undefined2 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined2 *puStack_14;
  
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  pcStack_18 = (code *)0x0;
  puStack_14 = (undefined2 *)0x0;
  uStack_2c = touchlink_transaction_id(0);
  if (param_1 == (undefined2 *)0x0) {
    uStack_28 = CONCAT31(uStack_28._1_3_,1);
    uVar3 = 0;
  }
  else {
    uVar1 = *(undefined4 *)((int)param_1 + 1);
    uVar2 = *(undefined4 *)((int)param_1 + 5);
    uStack_28 = CONCAT13((char)((uint)uVar1 >> 0x10),CONCAT12((char)((uint)uVar1 >> 8),*param_1));
    uStack_24 = CONCAT13((char)((uint)uVar2 >> 0x10),
                         CONCAT12((char)((uint)uVar2 >> 8),
                                  CONCAT11((char)*(undefined2 *)((int)param_1 + 5),
                                           (char)((uint)uVar1 >> 0x18))));
    uStack_20 = CONCAT31(uStack_20._1_3_,(char)((uint)uVar2 >> 0x18));
    uVar3 = touchlink_nwk_update_id();
    uVar1 = uStack_20;
    uStack_1c = CONCAT22(uStack_1c._2_2_,param_1[5]);
    uStack_20._3_1_ = SUB41(uVar1,3);
    uStack_20._0_3_ = CONCAT12(*(undefined1 *)(param_1 + 6),CONCAT11(uVar3,(undefined1)uStack_20));
    uVar3 = *(undefined1 *)((int)param_1 + 0x21);
  }
  pcStack_18 = touchlink_network_start_rsp_confirm;
  uStack_38 = CONCAT31(uStack_38._1_3_,3);
  puStack_14 = param_1;
  iVar4 = touchlink_transaction_get();
  uStack_34 = *(undefined4 *)(iVar4 + 10);
  uStack_38 = CONCAT22(*(undefined2 *)(iVar4 + 8),(undefined2)uStack_38);
  uStack_30._0_3_ = CONCAT12(uVar3,*(undefined2 *)(iVar4 + 0xe));
  zcl_touchlink_network_start_rsp(&uStack_38);
  return;
}

