/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_network_update.o -> touchlink_send_network_update_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_send_network_update_req(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 auStack_38 [2];
  undefined1 auStack_36 [10];
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  memset(auStack_38,0,0x28);
  uVar1 = 2;
  if (param_1 != 0) {
    iVar2 = touchlink_transaction_id(0);
    uVar1 = 3;
    if (iVar2 != 0) {
      uStack_2c = touchlink_transaction_id(0);
      uStack_20 = touchlink_nwk_update_id();
      uStack_1f = touchlink_current_channel();
      uStack_1e = touchlink_pan_id();
      uStack_1c = *(undefined2 *)(param_1 + 0x24);
      puVar3 = (undefined4 *)touchlink_extended_pan_id();
      uStack_28 = *puVar3;
      uStack_24 = puVar3[1];
      pcStack_18 = touchlink_network_update_req_confirm;
      auStack_38[0] = 3;
      uStack_14 = param_2;
      memcpy(auStack_36,(void *)(param_1 + 0xf),8);
      uVar1 = zcl_touchlink_network_update_req(auStack_38);
    }
  }
  return uVar1;
}

