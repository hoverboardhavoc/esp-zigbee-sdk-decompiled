/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_initiator_check_commissioning_device
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_initiator_check_commissioning_device(void *arg)

{
  touchlink_disc_dev_info_t *ptVar1;
  short asStack_12 [2];
  nwk_addr_ref_t ref;
  
  ptVar1 = touchlink_initiator_get_commissioning_device();
  if (ptVar1 == (touchlink_disc_dev_info_t *)0x0) {
    touchlink_commissioning_task_result('\x01');
  }
  else {
    asStack_12[0] = -1;
    nwk_address_ref_by_extended(&(ptVar1->basic).ieee_addr,asStack_12);
    if (asStack_12[0] == -1) {
      touchlink_commissioning_task_result('\x01');
    }
    else {
      touchlink_commissioning_task_result('\0');
    }
  }
  return;
}

