/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_initiator_start_association
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_initiator_start_association(void)

{
  touchlink_disc_dev_info_t *ptVar1;
  int *piVar2;
  int iVar3;
  ezb_err_t eVar4;
  uint uVar5;
  
  ptVar1 = touchlink_initiator_get_commissioning_device();
  if (ptVar1 == (touchlink_disc_dev_info_t *)0x0) {
    ptVar1 = touchlink_commissioning_select_suitable_device();
  }
  else {
    ptVar1 = touchlink_initiator_get_commissioning_device();
  }
  if (ptVar1 == (touchlink_disc_dev_info_t *)0x0) {
    eVar4 = 5;
  }
  else {
    touchlink_initiator_set_commissioning_device(ptVar1);
    touchlink_set_transaction_id((ptVar1->basic).transaction_id);
    touchlink_set_intrp_channel((ptVar1->basic).intrp_channel);
    piVar2 = (int *)touchlink_extended_address();
    if ((*(int *)&(ptVar1->basic).ieee_addr.field_0 == *piVar2) &&
       (*(int *)((int)&(ptVar1->basic).ieee_addr.field_0 + 4) == piVar2[1])) {
      touchlink_send_network_update_req(ptVar1,0);
      uVar5 = touchlink_touchlink_info();
      if ((uVar5 & 2) == 0) {
        touchlink_zdo_rejoin_network();
        eVar4 = 0;
      }
      else {
        eVar4 = 0;
      }
    }
    else {
      iVar3 = touchlink_is_factory_new();
      if (iVar3 == 0) {
        eVar4 = touchlink_commissioning_join_local_network(ptVar1);
      }
      else {
        eVar4 = touchlink_commissioning_start_new_network(ptVar1);
      }
    }
  }
  return eVar4;
}

