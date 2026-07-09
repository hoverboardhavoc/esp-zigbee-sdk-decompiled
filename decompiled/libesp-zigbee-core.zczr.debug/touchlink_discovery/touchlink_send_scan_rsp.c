/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_discovery.o -> touchlink_send_scan_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_send_scan_rsp(undefined1 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_40 = touchlink_transaction_id(0);
  uStack_3c = touchlink_response_id(1);
  uVar3 = touchlink_zigbee_info();
  uStack_38 = CONCAT31(uStack_38._1_3_,uVar3);
  uVar3 = touchlink_touchlink_info();
  uStack_38._0_2_ = CONCAT11(uVar3,(undefined1)uStack_38);
  uVar4 = touchlink_get_key_bitmask();
  uStack_38 = CONCAT22(uVar4,(undefined2)uStack_38);
  uVar3 = touchlink_get_rssi_correction();
  uStack_34 = CONCAT31(uStack_34._1_3_,uVar3);
  uVar3 = touchlink_nwk_update_id();
  uStack_2c._0_2_ = CONCAT11(uVar3,(undefined1)uStack_2c);
  uVar3 = touchlink_current_channel();
  uStack_2c._0_3_ = CONCAT12(uVar3,(undefined2)uStack_2c);
  uVar4 = touchlink_pan_id();
  uStack_28 = CONCAT22(uStack_28._2_2_,uVar4);
  uVar4 = touchlink_short_address();
  uStack_28 = CONCAT22(uVar4,(undefined2)uStack_28);
  uVar3 = touchlink_n_sub_device_size();
  uStack_24 = CONCAT31(uStack_24._1_3_,uVar3);
  uVar3 = touchlink_total_groups_size();
  uStack_24._0_2_ = CONCAT11(uVar3,(undefined1)uStack_24);
  puVar5 = (undefined4 *)touchlink_extended_pan_id();
  uVar1 = *puVar5;
  uVar2 = puVar5[1];
  uStack_34 = CONCAT13((char)((uint)uVar1 >> 0x10),
                       CONCAT12((char)((uint)uVar1 >> 8),
                                CONCAT11((char)*(undefined3 *)puVar5,(undefined1)uStack_34)));
  uStack_30 = CONCAT13((char)((uint)uVar2 >> 0x10),
                       CONCAT12((char)((uint)uVar2 >> 8),
                                CONCAT11((char)*(undefined3 *)(puVar5 + 1),
                                         (char)((uint)uVar1 >> 0x18))));
  uStack_2c = CONCAT31(uStack_2c._1_3_,(char)((uint)uVar2 >> 0x18));
  if (((uStack_24 & 0xff) == 1) &&
     (puVar7 = (undefined1 *)af_get_next_simple_desc(0), puVar7 != (undefined1 *)0x0)) {
    uStack_24._0_3_ = CONCAT12(*puVar7,(undefined2)uStack_24);
    uStack_20 = *(undefined4 *)(puVar7 + 2);
    uStack_1c = CONCAT31(uStack_1c._1_3_,(char)*(undefined2 *)(puVar7 + 6)) & 0xffffff0f;
    uStack_1c._0_2_ = (ushort)(byte)uStack_1c;
  }
  uStack_18 = 0x10000;
  uStack_14 = 0;
  uStack_4c = CONCAT31(uStack_4c._1_3_,3);
  iVar6 = touchlink_transaction_get();
  uStack_48 = *(undefined4 *)(iVar6 + 10);
  uStack_4c = CONCAT22(*(undefined2 *)(iVar6 + 8),(undefined2)uStack_4c);
  uStack_44._0_3_ = CONCAT12(param_1,*(undefined2 *)(iVar6 + 0xe));
  zcl_touchlink_scan_rsp(&uStack_4c);
  return;
}

