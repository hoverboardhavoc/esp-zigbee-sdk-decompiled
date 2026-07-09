/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_network_start.o -> touchlink_send_network_start_rsp_with_failure
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_send_network_start_rsp_with_failure(undefined1 param_1)

{
  int iVar1;
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
  uStack_2c = touchlink_transaction_id(0);
  uStack_28 = CONCAT31(uStack_28._1_3_,1);
  pcStack_18 = touchlink_network_start_rsp_confirm;
  uStack_14 = 0;
  uStack_38 = CONCAT31(uStack_38._1_3_,3);
  iVar1 = touchlink_transaction_get();
  uStack_34 = *(undefined4 *)(iVar1 + 10);
  uStack_38 = CONCAT22(*(undefined2 *)(iVar1 + 8),(undefined2)uStack_38);
  uStack_30._0_3_ = CONCAT12(param_1,*(undefined2 *)(iVar1 + 0xe));
  zcl_touchlink_network_start_rsp(&uStack_38);
  return;
}

