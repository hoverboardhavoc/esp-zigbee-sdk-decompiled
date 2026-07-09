/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_discovery.o -> touchlink_scan_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_scan_req_handler(int param_1)

{
  undefined4 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  undefined1 auStack_4c [2];
  undefined1 auStack_4a [8];
  undefined1 uStack_42;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined2 uStack_36;
  undefined1 uStack_34;
  undefined1 uStack_33;
  undefined1 uStack_32;
  undefined1 uStack_31;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined1 uStack_2e;
  undefined1 uStack_2d;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined2 uStack_28;
  undefined2 uStack_26;
  char cStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  byte bStack_1c;
  undefined1 uStack_1b;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0xc);
  if (iVar3 != 0) {
    piVar5 = (int *)touchlink_transaction_get();
    if (iVar3 == *piVar5) {
      iVar3 = touchlink_transaction_get();
      if ((*(int *)(param_1 + 2) == *(int *)(iVar3 + 8)) &&
         (*(int *)(param_1 + 6) == *(int *)(iVar3 + 0xc))) {
        return 3;
      }
    }
    touchlink_set_transaction_id(*(undefined4 *)(param_1 + 0xc));
    iVar3 = touchlink_transaction_get();
    uVar2 = *(undefined2 *)(param_1 + 6);
    uVar8 = *(undefined4 *)(param_1 + 2);
    uVar1 = *(undefined4 *)(param_1 + 6);
    *(char *)(iVar3 + 8) = (char)*(undefined2 *)(param_1 + 2);
    *(char *)(iVar3 + 9) = (char)((uint)uVar8 >> 8);
    *(char *)(iVar3 + 0xb) = (char)((uint)uVar8 >> 0x18);
    *(char *)(iVar3 + 0xd) = (char)((uint)uVar1 >> 8);
    *(char *)(iVar3 + 10) = (char)((uint)uVar8 >> 0x10);
    *(char *)(iVar3 + 0xc) = (char)uVar2;
    *(char *)(iVar3 + 0xe) = (char)((uint)uVar1 >> 0x10);
    *(char *)(iVar3 + 0xf) = (char)((uint)uVar1 >> 0x18);
    iVar3 = touchlink_transaction_get();
    *(undefined1 *)(iVar3 + 0x60c) = 1;
    iVar3 = touchlink_transaction_get();
    *(undefined1 *)(iVar3 + 0x610) = 0;
    iVar3 = touchlink_transaction_get();
    *(undefined4 *)(iVar3 + 0x614) = *(undefined4 *)(param_1 + 0xc);
    iVar3 = touchlink_transaction_get();
    *(undefined2 *)(iVar3 + 0x618) = 0x1e46;
    iVar3 = touchlink_transaction_get();
    uVar4 = touchlink_current_channel();
    *(undefined1 *)(iVar3 + 0x61a) = uVar4;
    iVar3 = touchlink_transaction_get();
    iVar3 = touchlink_schedule_transaction_event(iVar3 + 0x60c);
    if (iVar3 != 0) {
      return 0;
    }
    iVar3 = touchlink_device_info_get();
    if ((*(char *)(iVar3 + 3) < *(char *)(param_1 + 0xb)) &&
       ((*(byte *)(param_1 + 0x10) & 0x10) == 0)) {
      uVar4 = *(undefined1 *)(param_1 + 10);
      memset(auStack_4c,0,0x3c);
      uStack_40 = touchlink_transaction_id(0);
      uStack_3c = touchlink_response_id(1);
      uStack_38 = touchlink_zigbee_info();
      uStack_37 = touchlink_touchlink_info();
      uStack_36 = touchlink_get_key_bitmask();
      uStack_34 = touchlink_get_rssi_correction();
      uStack_2b = touchlink_nwk_update_id();
      uStack_2a = touchlink_current_channel();
      uStack_28 = touchlink_pan_id();
      uStack_26 = touchlink_short_address();
      cStack_24 = touchlink_n_sub_device_size();
      uStack_23 = touchlink_total_groups_size();
      puVar6 = (undefined4 *)touchlink_extended_pan_id();
      uVar8 = *puVar6;
      uVar1 = puVar6[1];
      uStack_33 = (undefined1)*(undefined3 *)puVar6;
      uStack_32 = (undefined1)((uint)uVar8 >> 8);
      uStack_30 = (undefined1)((uint)uVar8 >> 0x18);
      uStack_2e = (undefined1)((uint)uVar1 >> 8);
      uStack_2c = (undefined1)((uint)uVar1 >> 0x18);
      uStack_31 = (undefined1)((uint)uVar8 >> 0x10);
      uStack_2f = (undefined1)*(undefined3 *)(puVar6 + 1);
      uStack_2d = (undefined1)((uint)uVar1 >> 0x10);
      if ((cStack_24 == '\x01') &&
         (puVar7 = (undefined1 *)af_get_next_simple_desc(0), puVar7 != (undefined1 *)0x0)) {
        uStack_22 = *puVar7;
        uStack_20 = *(undefined2 *)(puVar7 + 2);
        uStack_1e = *(undefined2 *)(puVar7 + 4);
        uStack_1b = 0;
        bStack_1c = (byte)*(undefined2 *)(puVar7 + 6) & 0xf;
      }
      uStack_18 = 0x10000;
      auStack_4c[0] = 3;
      uStack_14 = 0;
      iVar3 = touchlink_transaction_get();
      memcpy(auStack_4a,(void *)(iVar3 + 8),8);
      uStack_42 = uVar4;
      uVar8 = zcl_touchlink_scan_rsp(auStack_4c);
      return uVar8;
    }
  }
  return 2;
}

