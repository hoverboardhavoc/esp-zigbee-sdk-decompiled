/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_network_update.o -> touchlink_network_update_req_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_network_update_req_confirm(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 extraout_a1;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  code *pcStack_28;
  undefined4 uStack_24;
  
  if (param_1 != (undefined1 *)0x0) {
    uVar3 = log_write(3,"TL_NETWORK_UPDATE","Touchlink network update request confirm, status: 0x%x"
                      ,*param_1);
    return uVar3;
  }
  iVar4 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/touchlink/touchlink_network_update.c"
                        ,0x12,"touchlink_network_update_req_confirm",0x10000);
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  pcStack_28 = (code *)0x0;
  uStack_24 = 0;
  if (iVar4 == 0) {
    uVar3 = 2;
  }
  else {
    iVar5 = touchlink_transaction_id(0);
    if (iVar5 == 0) {
      uVar3 = 3;
    }
    else {
      uStack_3c = touchlink_transaction_id(0);
      uVar1 = touchlink_nwk_update_id();
      uStack_30 = CONCAT31(uStack_30._1_3_,uVar1);
      uVar1 = touchlink_current_channel();
      uStack_30._0_2_ = CONCAT11(uVar1,(undefined1)uStack_30);
      uVar2 = touchlink_pan_id();
      uStack_30 = CONCAT22(uVar2,(undefined2)uStack_30);
      uStack_2c = CONCAT22(uStack_2c._2_2_,*(undefined2 *)(iVar4 + 0x24));
      puVar6 = (undefined4 *)touchlink_extended_pan_id();
      uStack_38 = *puVar6;
      uStack_34 = puVar6[1];
      pcStack_28 = touchlink_network_update_req_confirm;
      uStack_48 = CONCAT31(uStack_48._1_3_,3);
      uStack_44 = *(undefined4 *)(iVar4 + 0x11);
      uStack_48 = CONCAT13(*(undefined1 *)(iVar4 + 0x10),
                           CONCAT12(*(undefined1 *)(iVar4 + 0xf),(undefined2)uStack_48));
      uStack_40 = CONCAT22(uStack_40._2_2_,*(undefined2 *)(iVar4 + 0x15));
      uStack_24 = extraout_a1;
      uVar3 = zcl_touchlink_network_update_req(&uStack_48);
    }
  }
  return uVar3;
}

