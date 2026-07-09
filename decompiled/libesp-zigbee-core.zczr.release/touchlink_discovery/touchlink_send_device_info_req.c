/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_discovery.o -> touchlink_send_device_info_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_send_device_info_req(undefined1 param_1,void *param_2,undefined4 param_3)

{
  undefined1 auStack_2c [2];
  undefined1 auStack_2a [10];
  undefined4 uStack_20;
  undefined1 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  memset(auStack_2c,0,0x1c);
  uStack_20 = touchlink_transaction_id(0);
  pcStack_18 = touchlink_device_info_req_confirm;
  auStack_2c[0] = 3;
  uStack_1c = param_1;
  uStack_14 = param_3;
  memcpy(auStack_2a,param_2,8);
  zcl_touchlink_device_info_req(auStack_2c);
  return;
}

