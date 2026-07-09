/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_join_router.o -> touchlink_send_join_router_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_send_join_router_req(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 auStack_54 [2];
  undefined1 auStack_52 [10];
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 uStack_3c;
  undefined1 auStack_3b [16];
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  
  memset(auStack_54,0,0x44);
  uVar5 = 2;
  if (param_1 != 0) {
    iVar2 = touchlink_transaction_id(0);
    uVar5 = 3;
    if (iVar2 != 0) {
      iVar2 = touchlink_disc_table_entry_exists(param_1);
      uVar5 = 5;
      if ((iVar2 != 0) && ((*(ushort *)(param_1 + 8) & 3) == 1)) {
        uStack_48 = touchlink_transaction_id(0);
        puVar3 = (undefined4 *)touchlink_extended_pan_id();
        uStack_44 = *puVar3;
        uStack_40 = puVar3[1];
        uVar5 = touchlink_nwk_key();
        uVar1 = *(undefined2 *)(param_1 + 0xc);
        uVar4 = touchlink_transaction_id(0);
        uStack_3c = touchlink_encrypt_nwk_key
                              (uVar5,auStack_3b,uVar1,uVar4,*(undefined4 *)(param_1 + 4));
        uStack_2b = touchlink_nwk_update_id();
        uStack_2a = touchlink_current_channel();
        uStack_28 = touchlink_pan_id();
        uStack_26 = nwk_assign_shortaddr();
        uStack_24 = 0xfeff0001;
        uStack_1c = 0xfeff0001;
        uStack_20 = 0xfff70001;
        uStack_18 = 0x10000;
        iStack_14 = touchlink_transaction_get();
        iStack_14 = iStack_14 + 0x610;
        auStack_54[0] = 3;
        memcpy(auStack_52,(void *)(param_1 + 0xf),8);
        uVar5 = zcl_touchlink_network_join_router_req(auStack_54);
      }
    }
  }
  return uVar5;
}

