/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_discovery.o -> touchlink_send_scan_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int touchlink_send_scan_req(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_2c [2];
  undefined2 uStack_2a;
  undefined4 uStack_20;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  code *pcStack_18;
  undefined4 uStack_14;
  
  memset(auStack_2c,0,0x1c);
  uStack_20 = touchlink_transaction_id(param_1);
  uStack_1c = touchlink_zigbee_info();
  uStack_1b = touchlink_touchlink_info();
  pcStack_18 = touchlink_scan_req_confirm;
  auStack_2c[0] = 2;
  uStack_2a = 0xffff;
  uStack_14 = param_2;
  iVar1 = zcl_touchlink_scan_req(auStack_2c);
  if (iVar1 != 0) {
    touchlink_set_transaction_id(0);
  }
  return iVar1;
}

