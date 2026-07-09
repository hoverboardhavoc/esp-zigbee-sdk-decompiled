/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_initiator_start_association
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_initiator_start_association(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar1 = touchlink_initiator_get_commissioning_device();
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)touchlink_commissioning_select_suitable_device();
  }
  else {
    puVar2 = (undefined4 *)touchlink_initiator_get_commissioning_device();
  }
  if (puVar2 == (undefined4 *)0x0) {
    uVar4 = 5;
  }
  else {
    touchlink_initiator_set_commissioning_device(puVar2);
    touchlink_set_transaction_id(*puVar2);
    touchlink_set_intrp_channel(*(undefined1 *)((int)puVar2 + 0x21));
    piVar3 = (int *)touchlink_extended_address();
    if ((*(int *)((int)puVar2 + 0xf) == *piVar3) && (*(int *)((int)puVar2 + 0x13) == piVar3[1])) {
      touchlink_send_network_update_req(puVar2,0);
      uVar5 = touchlink_touchlink_info();
      if ((uVar5 & 2) == 0) {
        touchlink_zdo_rejoin_network();
        uVar4 = 0;
      }
      else {
        uVar4 = 0;
      }
    }
    else {
      iVar1 = touchlink_is_factory_new();
      if (iVar1 == 0) {
        uVar4 = touchlink_commissioning_join_local_network(puVar2);
      }
      else {
        uVar4 = touchlink_commissioning_start_new_network(puVar2);
      }
    }
  }
  return uVar4;
}

