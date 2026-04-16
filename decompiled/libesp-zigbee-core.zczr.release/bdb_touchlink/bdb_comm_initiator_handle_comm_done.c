/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> bdb_touchlink.o -> bdb_comm_initiator_handle_comm_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bdb_comm_initiator_handle_comm_done(zdo_comm_operation_t op,ezb_err_t error)

{
  undefined1 uVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined3 in_register_00002029;
  char *pcVar7;
  void *pvVar8;
  int iVar9;
  undefined2 auStack_12 [3];
  
  uVar3 = CONCAT31(in_register_00002029,op);
  if (uVar3 == 7) {
touchlink_initiator_process_device_start_done:
    iVar9 = touchlink_commissioning_get();
    uVar3 = (uint)*(byte *)(iVar9 + 1);
    if (uVar3 != 1) {
      uVar3 = __assert_func(0,0,0,0);
    }
    if (error == 0) {
      uVar3 = 0;
    }
    touchlink_commissioning_task_result(uVar3);
    return;
  }
  if (7 < uVar3) {
    if (uVar3 != 8) {
      return;
    }
    goto touchlink_initiator_process_device_start_done;
  }
  if (uVar3 == 2) {
    iVar9 = touchlink_commissioning_get();
    if (*(char *)(iVar9 + 1) != '\x01') goto _L0;
  }
  else {
    if (uVar3 != 3) {
      return;
    }
    iVar9 = touchlink_commissioning_get();
    if (*(char *)(iVar9 + 1) == '\x01') {
      if (error == 0) {
        return;
      }
      goto _L0;
    }
_L0:
    __assert_func(0,0,0,0);
  }
  if (error == 0) {
    pcVar7 = (char *)touchlink_commissioning_get();
    if (*pcVar7 == '\x03') {
      iVar9 = touchlink_transaction_get();
      *(undefined1 *)(iVar9 + 0x60c) = 5;
      iVar9 = touchlink_transaction_get();
      *(undefined1 *)(iVar9 + 0x610) = 0;
      iVar9 = touchlink_transaction_get();
      uVar1 = touchlink_get_logical_channel();
      *(undefined1 *)(iVar9 + 0x61c) = uVar1;
      iVar9 = touchlink_transaction_get();
      uVar2 = touchlink_assign_pan_id();
      *(undefined2 *)(iVar9 + 0x61a) = uVar2;
      iVar9 = touchlink_transaction_get();
      uVar2 = touchlink_assign_short_addr();
      *(undefined2 *)(iVar9 + 0x61e) = uVar2;
      iVar9 = touchlink_transaction_get();
      pvVar8 = (void *)touchlink_extended_address();
      memcpy((void *)(iVar9 + 0x611),pvVar8,8);
      iVar9 = touchlink_transaction_get();
      pvVar8 = (void *)touchlink_nwk_key();
      memcpy((void *)(iVar9 + 0x620),pvVar8,0x10);
    }
    iVar9 = touchlink_transaction_get();
    iVar9 = iVar9 + 0x610;
    if (iVar9 != 0) goto _L18;
    do {
      iVar9 = __assert_func(0,0,0,0);
_L18:
      nwk_set_extended_panid(iVar9 + 1);
      nwk_set_pan_channel((uint)(0x20 << (*(byte *)(iVar9 + 0xc) & 0x1f)) >> 5);
      nwk_set_panid(*(undefined2 *)(iVar9 + 10));
      nwk_set_short_address(*(undefined2 *)(iVar9 + 0xe));
      uVar4 = nwk_get_extended_address();
      uVar5 = touchlink_short_address();
      iVar6 = nwk_address_update(uVar4,uVar5,auStack_12);
    } while (iVar6 != 0);
    nwk_address_lock_ref(auStack_12[0]);
    iVar6 = core_globals_get();
    *(byte *)(iVar6 + 0xb18) = *(byte *)(iVar6 + 0xb18) | 1;
    nwk_secur_set_key(iVar9 + 0x10,0);
    nwk_secur_switch_key(0);
    zdo_initiate_commissioning(0x80);
    return;
  }
_L0:
  touchlink_commissioning_task_result(1);
  return;
}

