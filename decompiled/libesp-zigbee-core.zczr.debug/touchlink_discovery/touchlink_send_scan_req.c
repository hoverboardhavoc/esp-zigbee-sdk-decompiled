/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_discovery.o -> touchlink_send_scan_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int touchlink_send_scan_req(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
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
  uStack_20 = touchlink_transaction_id();
  uVar1 = touchlink_zigbee_info();
  uStack_1c = CONCAT31(uStack_1c._1_3_,uVar1);
  uVar1 = touchlink_touchlink_info();
  uStack_1c._0_2_ = CONCAT11(uVar1,(undefined1)uStack_1c);
  pcStack_18 = touchlink_scan_req_confirm;
  uStack_2c = CONCAT31(uStack_2c._1_3_,2);
  uStack_2c = CONCAT22(0xffff,(undefined2)uStack_2c);
  uStack_14 = param_1;
  iVar2 = zcl_touchlink_scan_req(&uStack_2c);
  if (iVar2 != 0) {
    touchlink_set_transaction_id(0);
  }
  return iVar2;
}

