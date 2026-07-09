/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> bdb_touchlink.o -> bdb_comm_initiator_handle_comm_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint bdb_comm_initiator_handle_comm_done(uint param_1,int param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  void *pvVar8;
  uint uVar9;
  undefined2 auStack_12 [3];
  
  if (param_1 == 7) {
touchlink_initiator_process_device_annce_done:
    iVar7 = touchlink_commissioning_get();
    uVar9 = (uint)*(byte *)(iVar7 + 1);
    if (uVar9 != 1) {
      uVar9 = __assert_func(0,0,0,0);
    }
    if (param_2 == 0) {
      uVar9 = 0;
    }
    uVar9 = touchlink_commissioning_task_result(uVar9);
    return uVar9;
  }
  if (7 < param_1) {
    if (param_1 != 8) {
      return param_1;
    }
    goto touchlink_initiator_process_device_annce_done;
  }
  if (param_1 == 2) {
    iVar7 = touchlink_commissioning_get();
    if (*(char *)(iVar7 + 1) != '\x01') goto _L0;
  }
  else {
    if (param_1 != 3) {
      return param_1;
    }
    uVar9 = touchlink_commissioning_get();
    if (*(char *)(uVar9 + 1) == '\x01') {
      if (param_2 == 0) {
        return uVar9;
      }
      goto _L0;
    }
_L0:
    __assert_func(0,0,0,0);
  }
  if (param_2 == 0) {
    pcVar6 = (char *)touchlink_commissioning_get();
    if (*pcVar6 == '\x03') {
      iVar7 = touchlink_transaction_get();
      *(undefined1 *)(iVar7 + 0x60c) = 5;
      iVar7 = touchlink_transaction_get();
      *(undefined1 *)(iVar7 + 0x610) = 0;
      iVar7 = touchlink_transaction_get();
      uVar1 = touchlink_get_logical_channel();
      *(undefined1 *)(iVar7 + 0x61c) = uVar1;
      iVar7 = touchlink_transaction_get();
      uVar2 = touchlink_assign_pan_id();
      *(undefined2 *)(iVar7 + 0x61a) = uVar2;
      iVar7 = touchlink_transaction_get();
      uVar2 = touchlink_assign_short_addr();
      *(undefined2 *)(iVar7 + 0x61e) = uVar2;
      iVar7 = touchlink_transaction_get();
      pvVar8 = (void *)touchlink_extended_address();
      memcpy((void *)(iVar7 + 0x611),pvVar8,8);
      iVar7 = touchlink_transaction_get();
      pvVar8 = (void *)touchlink_nwk_key();
      memcpy((void *)(iVar7 + 0x620),pvVar8,0x10);
    }
    iVar7 = touchlink_transaction_get();
    iVar7 = iVar7 + 0x610;
    if (iVar7 != 0) goto _L18;
    do {
      iVar7 = __assert_func(0,0,0,0);
_L18:
      nwk_set_extended_panid(iVar7 + 1);
      nwk_set_pan_channel((uint)(0x20 << (*(byte *)(iVar7 + 0xc) & 0x1f)) >> 5);
      nwk_set_panid(*(undefined2 *)(iVar7 + 10));
      nwk_set_short_address(*(undefined2 *)(iVar7 + 0xe));
      uVar3 = nwk_get_extended_address();
      uVar4 = touchlink_short_address();
      iVar5 = nwk_address_update(uVar3,uVar4,auStack_12);
    } while (iVar5 != 0);
    nwk_address_lock_ref(auStack_12[0]);
    iVar5 = core_globals_get();
    *(byte *)(iVar5 + 0xb18) = *(byte *)(iVar5 + 0xb18) | 1;
    nwk_secur_set_key(iVar7 + 0x10,0);
    nwk_secur_switch_key(0);
    zdo_initiate_commissioning(0x80);
    return 0;
  }
_L0:
  uVar9 = touchlink_commissioning_task_result(1);
  return uVar9;
}

