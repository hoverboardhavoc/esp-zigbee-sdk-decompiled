/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_schedule_transaction_event
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_schedule_transaction_event(touchlink_transaction_event_t *event)

{
  touchlink_commissioning_t *ptVar1;
  ezb_err_t eVar2;
  
  ptVar1 = touchlink_commissioning_get();
  if (ptVar1->role == '\x02') {
    eVar2 = touchlink_target_process_event(event);
  }
  else {
    ptVar1 = touchlink_commissioning_get();
    if (ptVar1->role == '\x01') {
      eVar2 = touchlink_initiator_process_event(event);
    }
    else {
      eVar2 = 3;
    }
  }
  return eVar2;
}

