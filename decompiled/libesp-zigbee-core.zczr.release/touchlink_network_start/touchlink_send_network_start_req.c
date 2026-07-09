/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_network_start.o -> touchlink_send_network_start_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_send_network_start_req(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined1 auStack_5c [2];
  undefined1 auStack_5a [10];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 uStack_44;
  undefined1 auStack_43 [16];
  undefined1 uStack_33;
  undefined2 uStack_32;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  undefined4 uStack_18;
  int iStack_14;
  
  memset(auStack_5c,0,0x4c);
  iVar2 = touchlink_disc_table_entry_exists(param_1);
  if (iVar2 == 0) {
    uVar3 = 5;
  }
  else {
    uVar3 = 5;
    if ((*(ushort *)(param_1 + 8) & 3) == 1) {
      uStack_50 = touchlink_transaction_id(0);
      uStack_4c = 0;
      uStack_48 = 0;
      iVar2 = touchlink_get_logical_channel();
      if (iVar2 == 0) {
        uStack_33 = *(undefined1 *)(param_1 + 0x20);
      }
      else {
        uStack_33 = touchlink_get_logical_channel();
      }
      uStack_32 = 0;
      if (*(short *)(param_1 + 0x22) != -1) {
        uStack_32 = touchlink_assign_pan_id();
      }
      uStack_30 = nwk_assign_shortaddr();
      uVar3 = touchlink_nwk_key();
      uVar1 = *(undefined2 *)(param_1 + 0xc);
      uVar4 = touchlink_transaction_id(0);
      uStack_44 = touchlink_encrypt_nwk_key
                            (uVar3,auStack_43,uVar1,uVar4,*(undefined4 *)(param_1 + 4));
      uStack_2e = 1;
      uStack_2c = 0x1feff;
      uStack_28 = 0x1fff7;
      uStack_24 = 0xfeff;
      puVar5 = (undefined4 *)touchlink_extended_address();
      uStack_22 = (undefined2)*(undefined3 *)puVar5;
      uStack_20 = (undefined2)((uint)*puVar5 >> 0x10);
      uStack_1e = (undefined2)*(undefined3 *)(puVar5 + 1);
      uStack_1c = (undefined2)((uint)puVar5[1] >> 0x10);
      uStack_1a = touchlink_short_address();
      uStack_18 = 0x10000;
      iStack_14 = touchlink_transaction_get();
      iStack_14 = iStack_14 + 0x610;
      auStack_5c[0] = 3;
      memcpy(auStack_5a,(void *)(param_1 + 0xf),8);
      uVar3 = zcl_touchlink_network_start_req(auStack_5c);
    }
  }
  return uVar3;
}

