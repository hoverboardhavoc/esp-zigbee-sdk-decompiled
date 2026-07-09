/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_network_start.o -> touchlink_send_network_start_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_send_network_start_rsp(undefined1 *param_1)

{
  int iVar1;
  undefined1 auStack_38 [2];
  undefined1 auStack_36 [8];
  undefined1 uStack_2e;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  undefined2 uStack_1c;
  code *pcStack_18;
  undefined1 *puStack_14;
  
  memset(auStack_38,0,0x28);
  uStack_2c = touchlink_transaction_id(0);
  if (param_1 == (undefined1 *)0x0) {
    uStack_28 = 1;
    uStack_2e = 0;
  }
  else {
    uStack_28 = *param_1;
    uStack_27 = param_1[1];
    uStack_25 = param_1[3];
    uStack_26 = param_1[2];
    uStack_24 = param_1[4];
    uStack_21 = param_1[7];
    uStack_20 = param_1[8];
    uStack_22 = (undefined1)((ushort)*(undefined2 *)(param_1 + 5) >> 8);
    uStack_23 = (undefined1)*(undefined2 *)(param_1 + 5);
    uStack_1f = touchlink_nwk_update_id();
    uStack_1c = *(undefined2 *)(param_1 + 10);
    uStack_2e = param_1[0x21];
    uStack_1e = param_1[0xc];
  }
  pcStack_18 = touchlink_network_start_rsp_confirm;
  auStack_38[0] = 3;
  puStack_14 = param_1;
  iVar1 = touchlink_transaction_get();
  memcpy(auStack_36,(void *)(iVar1 + 8),8);
  zcl_touchlink_network_start_rsp(auStack_38);
  return;
}

