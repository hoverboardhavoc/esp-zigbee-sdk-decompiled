/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_join_router.o -> touchlink_send_join_router_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_send_join_router_req(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined1 auStack_54 [2];
  undefined1 uStack_52;
  undefined1 uStack_51;
  undefined1 uStack_50;
  undefined1 uStack_4f;
  undefined1 uStack_4e;
  undefined1 uStack_4d;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 uStack_3c;
  undefined1 auStack_3b [16];
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  code *pcStack_18;
  int iStack_14;
  
  memset(auStack_54,0,0x44);
  if (param_1 == 0) {
    uVar3 = 2;
  }
  else {
    iVar2 = touchlink_transaction_id(0);
    if (iVar2 == 0) {
      uVar3 = 3;
    }
    else {
      iVar2 = touchlink_disc_table_entry_exists(param_1);
      if (iVar2 == 0) {
        uVar3 = 5;
      }
      else if ((*(ushort *)(param_1 + 8) & 3) == 1) {
        uStack_48 = touchlink_transaction_id(0);
        puVar4 = (undefined4 *)touchlink_extended_pan_id();
        uStack_44 = *puVar4;
        uStack_40 = puVar4[1];
        uVar3 = touchlink_nwk_key();
        uVar1 = *(undefined2 *)(param_1 + 0xc);
        uVar5 = touchlink_transaction_id(0);
        uStack_3c = touchlink_encrypt_nwk_key
                              (uVar3,auStack_3b,uVar1,uVar5,*(undefined4 *)(param_1 + 4));
        uStack_2b = touchlink_nwk_update_id();
        uStack_2a = touchlink_current_channel();
        uStack_28 = touchlink_pan_id();
        uStack_26 = nwk_assign_shortaddr();
        uStack_24 = 1;
        uStack_22 = 0xfeff;
        uStack_20 = 1;
        uStack_1e = 0xfff7;
        uStack_1c = 1;
        uStack_1a = 0xfeff;
        pcStack_18 = touchlink_join_router_req_confirm;
        iStack_14 = touchlink_transaction_get();
        iStack_14 = iStack_14 + 0x610;
        auStack_54[0] = 3;
        uStack_52 = *(undefined1 *)(param_1 + 0xf);
        uStack_51 = *(undefined1 *)(param_1 + 0x10);
        uStack_50 = *(undefined1 *)(param_1 + 0x11);
        uStack_4f = *(undefined1 *)(param_1 + 0x12);
        uStack_4e = *(undefined1 *)(param_1 + 0x13);
        uStack_4d = *(undefined1 *)(param_1 + 0x14);
        uStack_4c = *(undefined1 *)(param_1 + 0x15);
        uStack_4b = *(undefined1 *)(param_1 + 0x16);
        uVar3 = zcl_touchlink_network_join_router_req(auStack_54);
      }
      else {
        uVar3 = 5;
      }
    }
  }
  return uVar3;
}

